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
if ( V_34 -> V_50 ) {
V_27 = V_34 -> V_50 ( V_16 , V_8 ,
V_43 ) ;
if ( V_27 ) {
F_8 ( L_10 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
return V_27 ;
}
} else {
V_27 = V_34 -> F_15 ( V_16 , & V_8 -> V_46 ,
& V_8 -> V_45 ) ;
if ( ! V_27 ) {
F_8 ( L_11 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
return - V_40 ;
}
}
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_51 * V_34 ;
struct V_12 * V_9 ;
V_8 = V_2 -> V_10 [ V_44 ] ;
V_9 = V_2 -> V_52 [ V_44 ] ;
if ( ! V_8 || ! V_8 -> V_31 )
continue;
V_34 = V_9 -> V_39 ;
V_27 = V_34 -> F_15 ( V_9 , & V_8 -> V_46 ,
& V_8 -> V_45 ) ;
if ( ! V_27 ) {
F_8 ( L_12 ,
V_9 -> V_28 . V_29 ) ;
return - V_40 ;
}
}
return 0 ;
}
static bool
F_17 ( struct V_7 * V_2 )
{
return V_2 -> V_31 || V_2 -> V_53 ;
}
int
F_18 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_41 = V_14 -> V_19 . V_42 ;
struct V_12 * V_9 ;
struct V_7 * V_8 ;
int V_44 , V_27 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
V_9 = V_2 -> V_52 [ V_44 ] ;
V_8 = V_2 -> V_10 [ V_44 ] ;
if ( ! V_9 )
continue;
if ( ! F_19 ( & V_9 -> V_2 -> V_46 , & V_8 -> V_46 ) ) {
F_8 ( L_13 ,
V_9 -> V_28 . V_29 ) ;
V_8 -> V_31 = true ;
}
if ( V_9 -> V_2 -> V_54 != V_8 -> V_54 ) {
F_8 ( L_14 ,
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
int V_55 ;
V_9 = V_2 -> V_52 [ V_44 ] ;
V_8 = V_2 -> V_10 [ V_44 ] ;
if ( ! V_9 )
continue;
if ( V_9 -> V_2 -> V_56 != V_8 -> V_56 ) {
F_8 ( L_15 ,
V_9 -> V_28 . V_29 ) ;
V_8 -> V_53 = true ;
}
if ( ! F_17 ( V_8 ) )
continue;
F_8 ( L_16 ,
V_9 -> V_28 . V_29 ,
V_8 -> V_54 ? 'y' : 'n' ,
V_8 -> V_56 ? 'y' : 'n' ) ;
V_27 = F_20 ( V_2 , V_9 ) ;
if ( V_27 != 0 )
return V_27 ;
V_55 = F_21 ( V_2 ,
V_9 ) ;
if ( V_8 -> V_54 != ! ! V_55 ) {
F_8 ( L_17 ,
V_9 -> V_28 . V_29 ) ;
return - V_40 ;
}
}
return F_15 ( V_2 ) ;
}
int
F_22 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_57 = V_14 -> V_19 . V_58 ;
int V_41 = V_14 -> V_19 . V_42 ;
int V_44 , V_27 = 0 ;
for ( V_44 = 0 ; V_44 < V_57 ; V_44 ++ ) {
struct V_59 * V_34 ;
struct V_5 * V_6 = V_2 -> V_60 [ V_44 ] ;
struct V_3 * V_4 = V_2 -> V_61 [ V_44 ] ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
F_1 ( V_2 , V_4 , V_6 ) ;
if ( ! V_34 || ! V_34 -> V_50 )
continue;
V_27 = V_34 -> V_50 ( V_6 , V_4 ) ;
if ( V_27 ) {
F_8 ( L_18 ,
V_6 -> V_28 . V_29 ) ;
return V_27 ;
}
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_51 * V_34 ;
struct V_12 * V_9 = V_2 -> V_52 [ V_44 ] ;
if ( ! V_9 )
continue;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_50 )
continue;
V_27 = V_34 -> V_50 ( V_9 , V_2 -> V_10 [ V_44 ] ) ;
if ( V_27 ) {
F_8 ( L_19 ,
V_9 -> V_28 . V_29 ) ;
return V_27 ;
}
}
return V_27 ;
}
int F_23 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_27 ;
V_27 = F_18 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_22 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
return V_27 ;
}
static void
F_24 ( struct V_13 * V_14 , struct V_1 * V_62 )
{
int V_41 = V_62 -> V_14 -> V_19 . V_42 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_62 -> V_47 ; V_44 ++ ) {
struct V_25 * V_63 ;
struct V_20 * V_21 ;
struct V_48 * V_34 ;
struct V_15 * V_16 ;
struct V_7 * V_64 ;
V_63 = V_62 -> V_38 [ V_44 ] ;
V_21 = V_62 -> V_37 [ V_44 ] ;
if ( ! V_63 || ! V_63 -> V_9 )
continue;
V_64 = V_62 -> V_10 [ F_2 ( V_63 -> V_9 ) ] ;
if ( ! V_64 -> V_56 )
continue;
V_16 = V_63 -> V_23 ;
if ( F_3 ( ! V_16 ) )
continue;
V_34 = V_16 -> V_39 ;
F_8 ( L_20 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
if ( V_16 -> V_49 )
V_16 -> V_49 -> V_34 -> V_65 ( V_16 -> V_49 ) ;
if ( V_21 -> V_2 -> V_9 && V_34 -> V_66 )
V_34 -> V_66 ( V_16 ) ;
else if ( V_34 -> V_65 )
V_34 -> V_65 ( V_16 ) ;
else
V_34 -> V_67 ( V_16 , V_68 ) ;
if ( V_16 -> V_49 )
V_16 -> V_49 -> V_34 -> V_69 ( V_16 -> V_49 ) ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_51 * V_34 ;
struct V_12 * V_9 ;
struct V_7 * V_64 ;
V_9 = V_62 -> V_52 [ V_44 ] ;
V_64 = V_62 -> V_10 [ V_44 ] ;
if ( ! V_9 || ! F_17 ( V_9 -> V_2 ) )
continue;
if ( ! V_64 -> V_56 )
continue;
V_34 = V_9 -> V_39 ;
F_8 ( L_21 ,
V_9 -> V_28 . V_29 ) ;
if ( V_9 -> V_2 -> V_54 && V_34 -> V_66 )
V_34 -> V_66 ( V_9 ) ;
else if ( V_34 -> V_65 )
V_34 -> V_65 ( V_9 ) ;
else
V_34 -> V_67 ( V_9 , V_68 ) ;
}
}
static void
F_25 ( struct V_13 * V_14 , struct V_1 * V_62 )
{
int V_41 = V_62 -> V_14 -> V_19 . V_42 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_62 -> V_47 ; V_44 ++ ) {
struct V_20 * V_21 ;
V_21 = V_62 -> V_37 [ V_44 ] ;
if ( ! V_21 || ! V_21 -> V_16 )
continue;
F_3 ( ! V_21 -> V_16 -> V_9 ) ;
V_21 -> V_16 -> V_9 = NULL ;
V_21 -> V_16 = NULL ;
}
for ( V_44 = 0 ; V_44 < V_62 -> V_47 ; V_44 ++ ) {
struct V_20 * V_21 ;
V_21 = V_62 -> V_37 [ V_44 ] ;
if ( ! V_21 || ! V_21 -> V_2 -> V_9 )
continue;
if ( F_3 ( ! V_21 -> V_2 -> V_23 ) )
continue;
V_21 -> V_16 = V_21 -> V_2 -> V_23 ;
V_21 -> V_16 -> V_9 = V_21 -> V_2 -> V_9 ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_12 * V_9 ;
V_9 = V_62 -> V_52 [ V_44 ] ;
if ( ! V_9 )
continue;
V_9 -> V_46 = V_9 -> V_2 -> V_46 ;
V_9 -> V_70 = V_9 -> V_2 -> V_54 ;
V_9 -> V_71 = V_9 -> V_72 -> V_2 -> V_73 >> 16 ;
V_9 -> V_74 = V_9 -> V_72 -> V_2 -> V_75 >> 16 ;
}
}
static void
F_26 ( struct V_13 * V_14 , struct V_1 * V_62 )
{
int V_41 = V_62 -> V_14 -> V_19 . V_42 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_51 * V_34 ;
struct V_12 * V_9 ;
V_9 = V_62 -> V_52 [ V_44 ] ;
if ( ! V_9 || ! V_9 -> V_2 -> V_31 )
continue;
V_34 = V_9 -> V_39 ;
if ( V_9 -> V_2 -> V_54 ) {
F_8 ( L_22 ,
V_9 -> V_28 . V_29 ) ;
V_34 -> V_76 ( V_9 ) ;
}
}
for ( V_44 = 0 ; V_44 < V_62 -> V_47 ; V_44 ++ ) {
struct V_20 * V_21 ;
struct V_7 * V_77 ;
struct V_48 * V_34 ;
struct V_15 * V_16 ;
struct V_78 * V_46 , * V_45 ;
V_21 = V_62 -> V_37 [ V_44 ] ;
if ( ! V_21 || ! V_21 -> V_2 -> V_23 )
continue;
V_16 = V_21 -> V_2 -> V_23 ;
V_34 = V_16 -> V_39 ;
V_77 = V_21 -> V_2 -> V_9 -> V_2 ;
V_46 = & V_77 -> V_46 ;
V_45 = & V_77 -> V_45 ;
if ( ! V_77 -> V_31 )
continue;
F_8 ( L_23 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
V_34 -> V_79 ( V_16 , V_46 , V_45 ) ;
if ( V_16 -> V_49 && V_16 -> V_49 -> V_34 -> V_79 )
V_16 -> V_49 -> V_34 -> V_79 ( V_16 -> V_49 ,
V_46 , V_45 ) ;
}
}
void F_27 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
F_24 ( V_14 , V_2 ) ;
F_25 ( V_14 , V_2 ) ;
F_26 ( V_14 , V_2 ) ;
}
void F_28 ( struct V_13 * V_14 ,
struct V_1 * V_62 )
{
int V_41 = V_62 -> V_14 -> V_19 . V_42 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_51 * V_34 ;
struct V_12 * V_9 ;
V_9 = V_62 -> V_52 [ V_44 ] ;
if ( ! V_9 || ! F_17 ( V_9 -> V_2 ) )
continue;
if ( ! V_9 -> V_2 -> V_56 )
continue;
V_34 = V_9 -> V_39 ;
if ( V_9 -> V_2 -> V_54 ) {
F_8 ( L_24 ,
V_9 -> V_28 . V_29 ) ;
if ( V_34 -> V_54 )
V_34 -> V_54 ( V_9 ) ;
else
V_34 -> V_80 ( V_9 ) ;
}
}
for ( V_44 = 0 ; V_44 < V_62 -> V_47 ; V_44 ++ ) {
struct V_20 * V_21 ;
struct V_48 * V_34 ;
struct V_15 * V_16 ;
V_21 = V_62 -> V_37 [ V_44 ] ;
if ( ! V_21 || ! V_21 -> V_2 -> V_23 )
continue;
if ( ! V_21 -> V_2 -> V_9 -> V_2 -> V_56 )
continue;
V_16 = V_21 -> V_2 -> V_23 ;
V_34 = V_16 -> V_39 ;
F_8 ( L_25 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
if ( V_16 -> V_49 )
V_16 -> V_49 -> V_34 -> V_81 ( V_16 -> V_49 ) ;
if ( V_34 -> V_54 )
V_34 -> V_54 ( V_16 ) ;
else
V_34 -> V_80 ( V_16 ) ;
if ( V_16 -> V_49 )
V_16 -> V_49 -> V_34 -> V_54 ( V_16 -> V_49 ) ;
}
}
static void F_29 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_57 = V_14 -> V_19 . V_58 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_57 ; V_44 ++ ) {
struct V_5 * V_6 = V_2 -> V_60 [ V_44 ] ;
if ( ! V_6 || ! V_6 -> V_2 -> V_82 )
continue;
F_3 ( ! V_6 -> V_2 -> V_83 ) ;
F_30 ( V_6 -> V_2 -> V_82 , false ) ;
F_31 ( V_6 -> V_2 -> V_82 ) ;
V_6 -> V_2 -> V_82 = NULL ;
}
}
static bool F_32 ( struct V_13 * V_14 ,
struct V_1 * V_62 ,
struct V_12 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_84 ;
int V_57 = V_62 -> V_14 -> V_19 . V_58 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_57 ; V_44 ++ ) {
V_6 = V_62 -> V_60 [ V_44 ] ;
V_84 = V_62 -> V_61 [ V_44 ] ;
if ( ! V_6 )
continue;
if ( V_6 -> V_2 -> V_9 != V_9 &&
V_84 -> V_9 != V_9 )
continue;
if ( V_6 -> V_2 -> V_83 != V_84 -> V_83 )
return true ;
}
return false ;
}
void
F_33 ( struct V_13 * V_14 ,
struct V_1 * V_62 )
{
struct V_12 * V_9 ;
struct V_7 * V_64 ;
int V_41 = V_62 -> V_14 -> V_19 . V_42 ;
int V_44 , V_27 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
V_9 = V_62 -> V_52 [ V_44 ] ;
V_64 = V_62 -> V_10 [ V_44 ] ;
if ( ! V_9 )
continue;
V_64 -> V_54 = false ;
if ( ! V_9 -> V_2 -> V_54 )
continue;
if ( V_62 -> V_85 )
continue;
if ( ! F_32 ( V_14 , V_62 , V_9 ) )
continue;
V_27 = F_34 ( V_9 ) ;
if ( V_27 != 0 )
continue;
V_64 -> V_54 = true ;
V_64 -> V_86 = F_35 ( V_14 , V_44 ) ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
V_9 = V_62 -> V_52 [ V_44 ] ;
V_64 = V_62 -> V_10 [ V_44 ] ;
if ( ! V_9 || ! V_64 -> V_54 )
continue;
V_27 = F_36 ( V_14 -> V_87 [ V_44 ] . V_88 ,
V_64 -> V_86 !=
F_35 ( V_14 , V_44 ) ,
F_37 ( 50 ) ) ;
F_38 ( V_9 ) ;
}
}
int F_39 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
bool V_89 )
{
int V_27 ;
if ( V_89 )
return - V_90 ;
V_27 = F_40 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
F_41 ( V_14 , V_2 ) ;
F_29 ( V_14 , V_2 ) ;
F_27 ( V_14 , V_2 ) ;
F_42 ( V_14 , V_2 ) ;
F_28 ( V_14 , V_2 ) ;
F_33 ( V_14 , V_2 ) ;
F_43 ( V_14 , V_2 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
int F_40 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_57 = V_14 -> V_19 . V_58 ;
int V_27 , V_44 ;
for ( V_44 = 0 ; V_44 < V_57 ; V_44 ++ ) {
struct V_59 * V_34 ;
struct V_5 * V_6 = V_2 -> V_60 [ V_44 ] ;
struct V_91 * V_83 ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
V_83 = V_2 -> V_61 [ V_44 ] -> V_83 ;
if ( V_83 && V_34 -> V_92 ) {
V_27 = V_34 -> V_92 ( V_6 , V_83 ) ;
if ( V_27 )
goto V_93;
}
}
return 0 ;
V_93:
for ( V_44 -- ; V_44 >= 0 ; V_44 -- ) {
struct V_59 * V_34 ;
struct V_5 * V_6 = V_2 -> V_60 [ V_44 ] ;
struct V_91 * V_83 ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
V_83 = V_2 -> V_61 [ V_44 ] -> V_83 ;
if ( V_83 && V_34 -> V_94 )
V_34 -> V_94 ( V_6 , V_83 ) ;
}
return V_27 ;
}
void F_42 ( struct V_13 * V_14 ,
struct V_1 * V_62 )
{
int V_57 = V_14 -> V_19 . V_58 ;
int V_41 = V_14 -> V_19 . V_42 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_51 * V_34 ;
struct V_12 * V_9 = V_62 -> V_52 [ V_44 ] ;
if ( ! V_9 )
continue;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_95 )
continue;
V_34 -> V_95 ( V_9 ) ;
}
for ( V_44 = 0 ; V_44 < V_57 ; V_44 ++ ) {
struct V_59 * V_34 ;
struct V_5 * V_6 = V_62 -> V_60 [ V_44 ] ;
struct V_3 * V_84 ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
if ( ! V_34 )
continue;
V_84 = V_62 -> V_61 [ V_44 ] ;
if ( F_45 ( V_6 , V_84 ) &&
V_34 -> V_96 )
V_34 -> V_96 ( V_6 , V_84 ) ;
else
V_34 -> V_97 ( V_6 , V_84 ) ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_51 * V_34 ;
struct V_12 * V_9 = V_62 -> V_52 [ V_44 ] ;
if ( ! V_9 )
continue;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_98 )
continue;
V_34 -> V_98 ( V_9 ) ;
}
}
void F_43 ( struct V_13 * V_14 ,
struct V_1 * V_62 )
{
int V_57 = V_14 -> V_19 . V_58 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_57 ; V_44 ++ ) {
struct V_59 * V_34 ;
struct V_5 * V_6 = V_62 -> V_60 [ V_44 ] ;
struct V_91 * V_99 ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
V_99 = V_62 -> V_61 [ V_44 ] -> V_83 ;
if ( V_99 && V_34 -> V_94 )
V_34 -> V_94 ( V_6 , V_99 ) ;
}
}
void F_41 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_14 -> V_19 . V_47 ; V_44 ++ ) {
struct V_20 * V_21 = V_2 -> V_37 [ V_44 ] ;
if ( ! V_21 )
continue;
V_21 -> V_2 -> V_2 = V_2 ;
F_46 ( V_2 -> V_38 [ V_44 ] , V_21 -> V_2 ) ;
V_21 -> V_2 -> V_2 = NULL ;
}
for ( V_44 = 0 ; V_44 < V_14 -> V_19 . V_42 ; V_44 ++ ) {
struct V_12 * V_9 = V_2 -> V_52 [ V_44 ] ;
if ( ! V_9 )
continue;
V_9 -> V_2 -> V_2 = V_2 ;
F_46 ( V_2 -> V_10 [ V_44 ] , V_9 -> V_2 ) ;
V_9 -> V_2 -> V_2 = NULL ;
}
for ( V_44 = 0 ; V_44 < V_14 -> V_19 . V_58 ; V_44 ++ ) {
struct V_5 * V_6 = V_2 -> V_60 [ V_44 ] ;
if ( ! V_6 )
continue;
V_6 -> V_2 -> V_2 = V_2 ;
F_46 ( V_2 -> V_61 [ V_44 ] , V_6 -> V_2 ) ;
V_6 -> V_2 -> V_2 = NULL ;
}
}
int F_47 ( struct V_5 * V_6 ,
struct V_12 * V_9 ,
struct V_91 * V_83 ,
int V_100 , int V_101 ,
unsigned int V_102 , unsigned int V_103 ,
T_1 V_73 , T_1 V_75 ,
T_1 V_104 , T_1 V_105 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
V_2 = F_48 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_106 ;
V_2 -> V_107 = F_49 ( V_9 ) ;
V_108:
V_4 = F_50 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_93;
}
V_27 = F_51 ( V_4 , V_9 ) ;
if ( V_27 != 0 )
goto V_93;
F_52 ( V_4 , V_83 ) ;
V_4 -> V_100 = V_100 ;
V_4 -> V_101 = V_101 ;
V_4 -> V_103 = V_103 ;
V_4 -> V_102 = V_102 ;
V_4 -> V_73 = V_73 ;
V_4 -> V_75 = V_75 ;
V_4 -> V_105 = V_105 ;
V_4 -> V_104 = V_104 ;
V_27 = F_53 ( V_2 ) ;
if ( V_27 != 0 )
goto V_93;
if ( V_6 == V_9 -> V_109 )
V_2 -> V_85 = true ;
return 0 ;
V_93:
if ( V_27 == - V_110 )
goto V_111;
F_44 ( V_2 ) ;
return V_27 ;
V_111:
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
V_6 -> V_99 = V_6 -> V_83 ;
goto V_108;
}
int F_56 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_2 = F_48 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_106 ;
V_2 -> V_107 = F_49 ( V_6 -> V_9 ) ;
V_108:
V_4 = F_50 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_93;
}
V_27 = F_51 ( V_4 , NULL ) ;
if ( V_27 != 0 )
goto V_93;
F_52 ( V_4 , NULL ) ;
V_4 -> V_100 = 0 ;
V_4 -> V_101 = 0 ;
V_4 -> V_103 = 0 ;
V_4 -> V_102 = 0 ;
V_4 -> V_73 = 0 ;
V_4 -> V_75 = 0 ;
V_4 -> V_105 = 0 ;
V_4 -> V_104 = 0 ;
if ( V_6 == V_6 -> V_9 -> V_109 )
V_2 -> V_85 = true ;
V_27 = F_53 ( V_2 ) ;
if ( V_27 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_27 == - V_110 )
goto V_111;
F_44 ( V_2 ) ;
return V_27 ;
V_111:
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
V_6 -> V_99 = V_6 -> V_83 ;
goto V_108;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
struct V_13 * V_14 = V_113 -> V_9 -> V_14 ;
struct V_25 * V_43 ;
int V_41 = V_2 -> V_14 -> V_19 . V_42 ;
int V_27 , V_44 , V_114 ;
V_27 = F_58 ( & V_14 -> V_19 . V_22 ,
V_2 -> V_107 ) ;
if ( V_27 )
return V_27 ;
for ( V_44 = 0 ; V_44 < V_113 -> V_55 ; V_44 ++ ) {
V_43 = F_12 ( V_2 ,
V_113 -> V_37 [ V_44 ] ) ;
if ( F_10 ( V_43 ) )
return F_11 ( V_43 ) ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_12 * V_9 = V_2 -> V_52 [ V_44 ] ;
if ( ! V_9 )
continue;
V_27 = F_20 ( V_2 , V_9 ) ;
if ( V_27 )
return V_27 ;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_47 ; V_44 ++ ) {
struct V_20 * V_21 ;
V_21 = V_2 -> V_37 [ V_44 ] ;
V_43 = V_2 -> V_38 [ V_44 ] ;
if ( ! V_21 )
continue;
if ( V_43 -> V_9 == V_113 -> V_9 ) {
V_27 = F_13 ( V_43 ,
NULL ) ;
if ( V_27 )
return V_27 ;
}
for ( V_114 = 0 ; V_114 < V_113 -> V_55 ; V_114 ++ ) {
if ( V_113 -> V_37 [ V_114 ] == V_21 ) {
V_27 = F_13 ( V_43 ,
V_113 -> V_9 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_12 * V_9 = V_2 -> V_52 [ V_44 ] ;
struct V_7 * V_8 = V_2 -> V_10 [ V_44 ] ;
if ( ! V_9 )
continue;
if ( V_9 == V_113 -> V_9 )
continue;
V_8 -> V_54 =
F_21 ( V_2 , V_9 ) ;
}
return 0 ;
}
int F_59 ( struct V_112 * V_113 )
{
struct V_1 * V_2 ;
struct V_12 * V_9 = V_113 -> V_9 ;
struct V_7 * V_8 ;
struct V_3 * V_115 ;
int V_27 = 0 ;
V_2 = F_48 ( V_9 -> V_14 ) ;
if ( ! V_2 )
return - V_106 ;
V_2 -> V_107 = F_49 ( V_9 ) ;
V_108:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_93;
}
V_115 = F_50 ( V_2 , V_9 -> V_72 ) ;
if ( F_10 ( V_115 ) ) {
V_27 = F_11 ( V_115 ) ;
goto V_93;
}
if ( ! V_113 -> V_46 ) {
F_3 ( V_113 -> V_83 ) ;
F_3 ( V_113 -> V_55 ) ;
V_8 -> V_54 = false ;
V_8 -> V_56 = false ;
V_27 = F_51 ( V_115 , NULL ) ;
if ( V_27 != 0 )
goto V_93;
F_52 ( V_115 , NULL ) ;
goto V_80;
}
F_3 ( ! V_113 -> V_83 ) ;
F_3 ( ! V_113 -> V_55 ) ;
V_8 -> V_54 = true ;
V_8 -> V_56 = true ;
F_16 ( & V_8 -> V_46 , V_113 -> V_46 ) ;
V_27 = F_51 ( V_115 , V_9 ) ;
if ( V_27 != 0 )
goto V_93;
F_52 ( V_115 , V_113 -> V_83 ) ;
V_115 -> V_100 = 0 ;
V_115 -> V_101 = 0 ;
V_115 -> V_103 = V_113 -> V_46 -> V_116 ;
V_115 -> V_102 = V_113 -> V_46 -> V_117 ;
V_115 -> V_73 = V_113 -> V_71 << 16 ;
V_115 -> V_75 = V_113 -> V_74 << 16 ;
V_115 -> V_105 = V_113 -> V_46 -> V_116 << 16 ;
V_115 -> V_104 = V_113 -> V_46 -> V_117 << 16 ;
V_80:
V_27 = F_57 ( V_2 , V_113 ) ;
if ( V_27 )
goto V_93;
V_27 = F_53 ( V_2 ) ;
if ( V_27 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_27 == - V_110 )
goto V_111;
F_44 ( V_2 ) ;
return V_27 ;
V_111:
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
V_9 -> V_72 -> V_99 = V_9 -> V_72 -> V_83 ;
goto V_108;
}
int
F_60 ( struct V_12 * V_9 ,
struct V_118 * V_119 ,
T_2 V_120 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_27 = 0 ;
V_2 = F_48 ( V_9 -> V_14 ) ;
if ( ! V_2 )
return - V_106 ;
V_2 -> V_107 = V_9 -> V_14 -> V_19 . V_107 ;
V_108:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_93;
}
V_27 = F_61 ( V_9 , V_8 ,
V_119 , V_120 ) ;
if ( V_27 )
goto V_93;
V_27 = F_53 ( V_2 ) ;
if ( V_27 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_27 == - V_110 )
goto V_111;
F_44 ( V_2 ) ;
return V_27 ;
V_111:
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
goto V_108;
}
int
F_62 ( struct V_5 * V_6 ,
struct V_118 * V_119 ,
T_2 V_120 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
V_2 = F_48 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_106 ;
V_2 -> V_107 = V_6 -> V_14 -> V_19 . V_107 ;
V_108:
V_4 = F_50 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_93;
}
V_27 = F_63 ( V_6 , V_4 ,
V_119 , V_120 ) ;
if ( V_27 )
goto V_93;
V_27 = F_53 ( V_2 ) ;
if ( V_27 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_27 == - V_110 )
goto V_111;
F_44 ( V_2 ) ;
return V_27 ;
V_111:
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
goto V_108;
}
int
F_64 ( struct V_20 * V_21 ,
struct V_118 * V_119 ,
T_2 V_120 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
int V_27 = 0 ;
V_2 = F_48 ( V_21 -> V_14 ) ;
if ( ! V_2 )
return - V_106 ;
V_2 -> V_107 = V_21 -> V_14 -> V_19 . V_107 ;
V_108:
V_26 = F_12 ( V_2 , V_21 ) ;
if ( F_10 ( V_26 ) ) {
V_27 = F_11 ( V_26 ) ;
goto V_93;
}
V_27 = F_65 ( V_21 , V_26 ,
V_119 , V_120 ) ;
if ( V_27 )
goto V_93;
V_27 = F_53 ( V_2 ) ;
if ( V_27 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_27 == - V_110 )
goto V_111;
F_44 ( V_2 ) ;
return V_27 ;
V_111:
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
goto V_108;
}
int F_66 ( struct V_12 * V_9 ,
struct V_91 * V_83 ,
struct V_121 * V_122 ,
T_1 V_123 )
{
struct V_5 * V_6 = V_9 -> V_72 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
int V_27 = 0 ;
if ( V_123 & V_124 )
return - V_40 ;
V_2 = F_48 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_106 ;
V_2 -> V_107 = F_49 ( V_9 ) ;
V_108:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_93;
}
V_8 -> V_122 = V_122 ;
V_4 = F_50 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_93;
}
V_27 = F_51 ( V_4 , V_9 ) ;
if ( V_27 != 0 )
goto V_93;
F_52 ( V_4 , V_83 ) ;
V_27 = F_67 ( V_2 ) ;
if ( V_27 != 0 )
goto V_93;
V_6 -> V_83 = V_6 -> V_2 -> V_83 ;
return 0 ;
V_93:
if ( V_27 == - V_110 )
goto V_111;
F_44 ( V_2 ) ;
return V_27 ;
V_111:
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
V_6 -> V_99 = V_6 -> V_83 ;
goto V_108;
}
void F_68 ( struct V_20 * V_21 ,
int V_46 )
{
struct V_17 * V_18 = & V_21 -> V_14 -> V_19 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_12 * V_9 ;
struct V_20 * V_125 ;
int V_27 ;
bool V_56 = false ;
if ( V_46 != V_126 )
V_46 = V_68 ;
V_21 -> V_67 = V_46 ;
V_9 = V_21 -> V_2 -> V_9 ;
if ( ! V_9 )
return;
V_2 = F_48 ( V_21 -> V_14 ) ;
if ( ! V_2 )
return;
V_2 -> V_107 = F_49 ( V_9 ) ;
V_108:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) )
return;
F_3 ( ! F_5 ( & V_18 -> V_22 ) ) ;
F_6 (tmp_connector, &config->connector_list, head) {
if ( V_21 -> V_2 -> V_9 != V_9 )
continue;
if ( V_21 -> V_67 == V_126 ) {
V_56 = true ;
break;
}
}
V_8 -> V_56 = V_56 ;
V_27 = F_53 ( V_2 ) ;
if ( V_27 != 0 )
goto V_93;
return;
V_93:
if ( V_27 == - V_110 )
goto V_111;
F_44 ( V_2 ) ;
F_69 ( 1 , L_26 , V_27 ) ;
return;
V_111:
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
goto V_108;
}
void F_70 ( struct V_12 * V_9 )
{
F_71 ( V_9 -> V_2 ) ;
V_9 -> V_2 = F_72 ( sizeof( * V_9 -> V_2 ) , V_127 ) ;
if ( V_9 -> V_2 )
V_9 -> V_2 -> V_9 = V_9 ;
}
struct V_7 *
F_73 ( struct V_12 * V_9 )
{
struct V_7 * V_2 ;
if ( F_3 ( ! V_9 -> V_2 ) )
return NULL ;
V_2 = F_74 ( V_9 -> V_2 , sizeof( * V_9 -> V_2 ) , V_127 ) ;
if ( V_2 ) {
V_2 -> V_31 = false ;
V_2 -> V_53 = false ;
V_2 -> V_11 = false ;
V_2 -> V_122 = NULL ;
}
return V_2 ;
}
void F_75 ( struct V_12 * V_9 ,
struct V_7 * V_2 )
{
F_71 ( V_2 ) ;
}
void F_76 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 && V_6 -> V_2 -> V_83 )
F_77 ( V_6 -> V_2 -> V_83 ) ;
F_71 ( V_6 -> V_2 ) ;
V_6 -> V_2 = F_72 ( sizeof( * V_6 -> V_2 ) , V_127 ) ;
if ( V_6 -> V_2 )
V_6 -> V_2 -> V_6 = V_6 ;
}
struct V_3 *
F_78 ( struct V_5 * V_6 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_6 -> V_2 ) )
return NULL ;
V_2 = F_74 ( V_6 -> V_2 , sizeof( * V_6 -> V_2 ) , V_127 ) ;
if ( V_2 && V_2 -> V_83 )
F_79 ( V_2 -> V_83 ) ;
return V_2 ;
}
void F_80 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
if ( V_2 -> V_83 )
F_77 ( V_2 -> V_83 ) ;
F_71 ( V_2 ) ;
}
void F_81 ( struct V_20 * V_21 )
{
F_71 ( V_21 -> V_2 ) ;
V_21 -> V_2 = F_72 ( sizeof( * V_21 -> V_2 ) , V_127 ) ;
if ( V_21 -> V_2 )
V_21 -> V_2 -> V_21 = V_21 ;
}
struct V_25 *
F_82 ( struct V_20 * V_21 )
{
if ( F_3 ( ! V_21 -> V_2 ) )
return NULL ;
return F_74 ( V_21 -> V_2 , sizeof( * V_21 -> V_2 ) , V_127 ) ;
}
void F_83 ( struct V_20 * V_21 ,
struct V_25 * V_2 )
{
F_71 ( V_2 ) ;
}
