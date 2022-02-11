static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & V_4 . V_5 [ V_3 -> V_6 ] ;
}
static struct V_7 * F_2 ( struct V_8 * V_9 )
{
return & V_4 . V_10 [ V_9 -> V_6 ] ;
}
void F_3 ( void )
{
const int V_11 = F_4 () ;
struct V_7 * V_12 ;
int V_13 ;
F_5 ( & V_14 ) ;
for ( V_13 = 0 ; V_13 < V_11 ; ++ V_13 ) {
struct V_1 * V_15 ;
V_15 = & V_4 . V_5 [ V_13 ] ;
V_15 -> V_16 . V_17 = 255 ;
switch ( V_13 ) {
case 0 :
V_15 -> V_16 . V_18 = 0 ;
break;
case 1 :
V_15 -> V_16 . V_18 =
F_6 ( V_19 ) ? 3 : 0 ;
break;
case 2 :
V_15 -> V_16 . V_18 =
F_6 ( V_19 ) ? 2 : 0 ;
break;
case 3 :
V_15 -> V_16 . V_18 =
F_6 ( V_19 ) ? 1 : 0 ;
break;
}
V_15 -> V_20 = V_15 -> V_16 ;
}
V_12 = & V_4 . V_10 [ V_21 ] ;
V_12 -> V_22 . V_23 = 24 ;
V_12 -> V_22 . V_24 . V_25 = 1 ;
V_12 -> V_22 . V_24 . V_26 = 1 ;
}
static bool F_7 ( struct V_2 * V_3 )
{
struct V_7 * V_12 = F_2 ( V_3 -> V_27 ) ;
return V_12 -> V_22 . V_28 ;
}
static bool F_8 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
return V_12 -> V_22 . V_28 ;
}
static int F_9 ( struct V_8 * V_9 ,
bool V_29 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_2 * V_3 ;
struct V_30 * V_34 [ V_35 ] ;
struct V_1 * V_15 ;
struct V_7 * V_12 ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_36 )
return 0 ;
if ( V_29 && V_12 -> V_37 )
V_33 = & V_12 -> V_20 ;
else
V_33 = & V_12 -> V_16 ;
F_10 (ovl, &mgr->overlays, list) {
V_15 = F_1 ( V_3 ) ;
if ( ! V_15 -> V_36 && ! V_15 -> V_38 )
V_31 = NULL ;
else if ( V_29 && V_15 -> V_37 )
V_31 = & V_15 -> V_20 ;
else
V_31 = & V_15 -> V_16 ;
V_34 [ V_3 -> V_6 ] = V_31 ;
}
return F_11 ( V_9 , V_33 , & V_12 -> V_39 , & V_12 -> V_22 , V_34 ) ;
}
static int F_12 ( struct V_8 * V_9 )
{
return F_9 ( V_9 , false ) ;
}
static int F_13 ( struct V_8 * V_9 )
{
return F_9 ( V_9 , true ) ;
}
static bool F_14 ( void )
{
const int V_40 = F_15 () ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
struct V_2 * V_3 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_36 )
continue;
if ( F_8 ( V_9 ) ) {
if ( V_12 -> V_41 )
return true ;
} else {
if ( V_12 -> V_42 )
return true ;
if ( V_12 -> V_43 )
return true ;
if ( V_12 -> V_44 )
return true ;
if ( V_12 -> V_45 )
return true ;
if ( V_12 -> V_46 )
return true ;
F_10 (ovl, &mgr->overlays, list) {
struct V_1 * V_15 ;
V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_45 )
return true ;
if ( V_15 -> V_46 )
return true ;
if ( ! V_15 -> V_36 )
continue;
if ( V_15 -> V_43 )
return true ;
if ( V_15 -> V_44 )
return true ;
}
}
}
return false ;
}
static bool F_17 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_7 * V_12 ;
struct V_1 * V_15 ;
V_12 = F_2 ( V_9 ) ;
if ( V_12 -> V_44 || V_12 -> V_46 )
return true ;
F_10 (ovl, &mgr->overlays, list) {
V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_44 || V_15 -> V_46 )
return true ;
}
return false ;
}
static bool F_18 ( void )
{
const int V_40 = F_15 () ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 ) {
struct V_8 * V_9 ;
struct V_2 * V_3 ;
struct V_7 * V_12 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_36 )
continue;
if ( ! V_12 -> V_41 )
continue;
if ( V_12 -> V_45 || V_12 -> V_46 )
return true ;
F_10 (ovl, &mgr->overlays, list) {
struct V_1 * V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_45 || V_15 -> V_46 )
return true ;
}
}
return false ;
}
static void F_19 ( void )
{
bool V_41 ;
unsigned long V_47 ;
unsigned long V_48 ;
int V_49 ;
F_20 ( & V_14 , V_47 ) ;
V_41 = F_18 () ;
if ( ! V_41 ) {
F_21 ( & V_14 , V_47 ) ;
return;
}
F_22 ( & V_50 ) ;
F_21 ( & V_14 , V_47 ) ;
V_48 = F_23 ( 500 ) ;
V_49 = F_24 ( & V_50 , V_48 ) ;
if ( V_49 == 0 )
F_25 ( L_1 ) ;
else if ( V_49 < 0 )
F_26 ( L_2 , V_49 ) ;
}
int F_27 ( struct V_8 * V_9 )
{
unsigned long V_51 = F_23 ( 500 ) ;
struct V_7 * V_12 ;
T_1 V_52 ;
int V_49 ;
int V_13 ;
struct V_53 * V_54 = V_9 -> V_55 ;
if ( ! V_54 || V_54 -> V_56 != V_57 )
return 0 ;
if ( F_8 ( V_9 ) )
return 0 ;
V_49 = F_28 () ;
if ( V_49 )
return V_49 ;
V_52 = F_29 ( V_9 -> V_6 ) ;
V_12 = F_2 ( V_9 ) ;
V_13 = 0 ;
while ( 1 ) {
unsigned long V_47 ;
bool V_58 , V_59 ;
F_20 ( & V_14 , V_47 ) ;
V_59 = V_12 -> V_43 ;
V_58 = V_12 -> V_44 ;
F_21 ( & V_14 , V_47 ) ;
if ( ! V_59 && ! V_58 ) {
V_49 = 0 ;
break;
}
if ( V_13 ++ == 3 ) {
F_26 ( L_3 ,
V_9 -> V_6 ) ;
V_49 = 0 ;
break;
}
V_49 = F_30 ( V_52 , V_51 ) ;
if ( V_49 == - V_60 )
break;
if ( V_49 ) {
F_26 ( L_4 , V_9 -> V_6 ) ;
break;
}
}
F_31 () ;
return V_49 ;
}
int F_32 ( struct V_2 * V_3 )
{
unsigned long V_51 = F_23 ( 500 ) ;
struct V_1 * V_15 ;
struct V_53 * V_54 ;
T_1 V_52 ;
int V_49 ;
int V_13 ;
if ( ! V_3 -> V_27 )
return 0 ;
V_54 = V_3 -> V_27 -> V_55 ;
if ( ! V_54 || V_54 -> V_56 != V_57 )
return 0 ;
if ( F_7 ( V_3 ) )
return 0 ;
V_49 = F_28 () ;
if ( V_49 )
return V_49 ;
V_52 = F_29 ( V_3 -> V_27 -> V_6 ) ;
V_15 = F_1 ( V_3 ) ;
V_13 = 0 ;
while ( 1 ) {
unsigned long V_47 ;
bool V_58 , V_59 ;
F_20 ( & V_14 , V_47 ) ;
V_59 = V_15 -> V_43 ;
V_58 = V_15 -> V_44 ;
F_21 ( & V_14 , V_47 ) ;
if ( ! V_59 && ! V_58 ) {
V_49 = 0 ;
break;
}
if ( V_13 ++ == 3 ) {
F_26 ( L_5 ,
V_3 -> V_6 ) ;
V_49 = 0 ;
break;
}
V_49 = F_30 ( V_52 , V_51 ) ;
if ( V_49 == - V_60 )
break;
if ( V_49 ) {
F_26 ( L_6 , V_3 -> V_6 ) ;
break;
}
}
F_31 () ;
return V_49 ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_30 * V_31 ;
bool V_61 ;
struct V_7 * V_12 ;
int V_49 ;
F_34 ( L_7 , V_3 -> V_6 ) ;
if ( ! V_15 -> V_36 || ! V_15 -> V_43 )
return;
V_31 = & V_15 -> V_16 ;
V_12 = F_2 ( V_3 -> V_27 ) ;
V_61 = F_35 ( V_12 -> V_22 , V_31 -> V_62 ) ;
V_49 = F_36 ( V_3 -> V_6 , V_31 , V_61 , & V_12 -> V_39 ) ;
if ( V_49 ) {
F_26 ( L_8 , V_3 -> V_6 ) ;
V_15 -> V_36 = false ;
F_37 ( V_3 -> V_6 , false ) ;
return;
}
V_15 -> V_43 = false ;
if ( V_12 -> V_41 )
V_15 -> V_44 = true ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_7 * V_12 ;
F_34 ( L_7 , V_3 -> V_6 ) ;
if ( ! V_15 -> V_45 )
return;
F_37 ( V_3 -> V_6 , V_15 -> V_36 ) ;
F_39 ( V_3 -> V_6 , V_15 -> V_63 ) ;
F_40 ( V_3 -> V_6 , V_15 -> V_64 , V_15 -> V_65 ) ;
V_12 = F_2 ( V_3 -> V_27 ) ;
V_15 -> V_45 = false ;
if ( V_12 -> V_41 )
V_15 -> V_46 = true ;
}
static void F_41 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
struct V_2 * V_3 ;
F_34 ( L_7 , V_9 -> V_6 ) ;
if ( ! V_12 -> V_36 )
return;
F_42 ( V_12 -> V_42 ) ;
F_10 (ovl, &mgr->overlays, list) {
F_33 ( V_3 ) ;
F_38 ( V_3 ) ;
}
if ( V_12 -> V_43 ) {
F_43 ( V_9 -> V_6 , & V_12 -> V_16 ) ;
V_12 -> V_43 = false ;
if ( V_12 -> V_41 )
V_12 -> V_44 = true ;
}
}
static void F_44 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_34 ( L_7 , V_9 -> V_6 ) ;
if ( ! V_12 -> V_45 )
return;
F_45 ( V_9 -> V_6 , & V_12 -> V_39 ) ;
if ( F_46 ( V_9 -> V_6 ) ) {
F_47 ( V_12 -> V_22 . V_66 ) ;
F_48 ( V_9 -> V_6 , V_12 -> V_22 . V_28 ) ;
F_49 ( V_9 -> V_6 ,
V_12 -> V_22 . V_67 ) ;
F_50 ( V_9 -> V_6 , & V_12 -> V_22 . V_24 ) ;
F_51 ( V_9 -> V_6 ,
V_12 -> V_22 . V_23 ) ;
F_52 ( V_12 -> V_22 . V_68 ) ;
F_53 ( V_9 -> V_6 ) ;
}
V_12 -> V_45 = false ;
if ( V_12 -> V_41 )
V_12 -> V_46 = true ;
}
static void F_54 ( void )
{
const int V_40 = F_55 () ;
int V_13 ;
if ( ! V_4 . V_69 )
return;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( V_12 -> V_36 ) {
if ( V_4 . V_69 ) {
F_56 ( V_4 . V_70 ) ;
V_4 . V_69 = false ;
}
if ( V_12 -> V_41 )
V_12 -> V_44 = true ;
}
}
}
static void F_57 ( void )
{
const int V_40 = F_55 () ;
int V_13 ;
F_54 () ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
int V_49 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_36 || F_8 ( V_9 ) || V_12 -> V_42 )
continue;
V_49 = F_12 ( V_9 ) ;
if ( V_49 ) {
F_26 ( L_9
L_10 , V_9 -> V_71 ) ;
continue;
}
F_41 ( V_9 ) ;
F_44 ( V_9 ) ;
}
}
static void F_58 ( void )
{
const int V_40 = F_55 () ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_36 || F_8 ( V_9 ) || V_12 -> V_42 )
continue;
if ( ! F_17 ( V_9 ) )
continue;
V_12 -> V_42 = true ;
if ( ! V_4 . V_72 && F_14 () )
F_59 () ;
F_60 ( V_9 -> V_6 ) ;
}
}
static void F_61 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_7 * V_12 ;
struct V_1 * V_15 ;
V_12 = F_2 ( V_9 ) ;
V_12 -> V_44 = false ;
V_12 -> V_46 = false ;
F_10 (ovl, &mgr->overlays, list) {
V_15 = F_1 ( V_3 ) ;
V_15 -> V_44 = false ;
V_15 -> V_46 = false ;
}
}
void F_62 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
int V_49 ;
F_20 ( & V_14 , V_47 ) ;
F_42 ( V_12 -> V_41 ) ;
V_49 = F_12 ( V_9 ) ;
if ( V_49 ) {
F_26 ( L_11 ) ;
F_21 ( & V_14 , V_47 ) ;
return;
}
F_41 ( V_9 ) ;
F_44 ( V_9 ) ;
F_54 () ;
V_12 -> V_41 = true ;
if ( ! V_4 . V_72 && F_14 () )
F_59 () ;
F_63 ( V_9 -> V_6 , true ) ;
F_61 ( V_9 ) ;
F_21 ( & V_14 , V_47 ) ;
}
static void F_59 ( void )
{
const int V_40 = F_15 () ;
T_1 V_73 ;
int V_49 , V_13 ;
V_73 = 0 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 )
V_73 |= F_29 ( V_13 ) ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 )
V_73 |= F_64 ( V_13 ) ;
V_49 = F_65 ( V_74 , NULL , V_73 ) ;
F_42 ( V_49 ) ;
V_4 . V_72 = true ;
}
static void F_66 ( void )
{
const int V_40 = F_15 () ;
T_1 V_73 ;
int V_49 , V_13 ;
V_73 = 0 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 )
V_73 |= F_29 ( V_13 ) ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 )
V_73 |= F_64 ( V_13 ) ;
V_49 = F_67 ( V_74 , NULL , V_73 ) ;
F_42 ( V_49 ) ;
V_4 . V_72 = false ;
}
static void V_74 ( void * V_75 , T_1 V_73 )
{
const int V_40 = F_15 () ;
int V_13 ;
bool V_76 ;
F_68 ( & V_14 ) ;
for ( V_13 = 0 ; V_13 < V_40 ; V_13 ++ ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
bool V_77 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_36 )
continue;
V_77 = V_12 -> V_41 ;
V_12 -> V_41 = F_69 ( V_13 ) ;
if ( ! F_8 ( V_9 ) ) {
bool V_78 = V_12 -> V_42 ;
V_12 -> V_42 = F_70 ( V_13 ) ;
if ( V_78 && ! V_12 -> V_42 )
F_61 ( V_9 ) ;
}
}
F_57 () ;
F_58 () ;
V_76 = F_18 () ;
if ( ! V_76 )
F_71 ( & V_50 ) ;
if ( ! F_14 () )
F_66 () ;
F_72 ( & V_14 ) ;
}
static void F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_15 ;
V_15 = F_1 ( V_3 ) ;
if ( ! V_15 -> V_37 )
return;
V_15 -> V_37 = false ;
V_15 -> V_43 = true ;
V_15 -> V_16 = V_15 -> V_20 ;
}
static void F_74 ( struct V_8 * V_9 )
{
struct V_7 * V_12 ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_37 )
return;
V_12 -> V_37 = false ;
V_12 -> V_43 = true ;
V_12 -> V_16 = V_12 -> V_20 ;
}
int F_75 ( struct V_8 * V_9 )
{
unsigned long V_47 ;
struct V_2 * V_3 ;
int V_49 ;
F_76 ( L_12 , V_9 -> V_71 ) ;
F_20 ( & V_14 , V_47 ) ;
V_49 = F_13 ( V_9 ) ;
if ( V_49 ) {
F_21 ( & V_14 , V_47 ) ;
F_26 ( L_13 ) ;
return V_49 ;
}
F_10 (ovl, &mgr->overlays, list)
F_73 ( V_3 ) ;
F_74 ( V_9 ) ;
F_57 () ;
F_58 () ;
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
static void F_77 ( struct V_2 * V_3 , bool V_79 )
{
struct V_1 * V_15 ;
V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_36 == V_79 )
return;
V_15 -> V_36 = V_79 ;
V_15 -> V_45 = true ;
}
static void F_78 ( struct V_2 * V_3 ,
T_1 V_64 , T_1 V_65 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_64 == V_64 && V_15 -> V_65 == V_65 )
return;
V_15 -> V_64 = V_64 ;
V_15 -> V_65 = V_65 ;
V_15 -> V_45 = true ;
}
static void F_79 ( bool V_80 )
{
if ( V_4 . V_70 == V_80 )
return;
V_4 . V_70 = V_80 ;
V_4 . V_69 = true ;
}
static void F_80 ( struct V_2 * V_3 ,
bool V_80 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
T_1 V_64 , V_65 ;
if ( ! V_15 -> V_36 && ! V_15 -> V_38 )
return;
F_81 ( V_3 -> V_6 , & V_64 , & V_65 ,
V_80 , F_7 ( V_3 ) ) ;
F_78 ( V_3 , V_64 , V_65 ) ;
}
static void F_82 ( struct V_8 * V_9 ,
bool V_80 )
{
struct V_2 * V_3 ;
struct V_7 * V_12 ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_36 )
return;
F_10 (ovl, &mgr->overlays, list)
F_80 ( V_3 , V_80 ) ;
}
static void F_83 ( bool V_80 )
{
const int V_40 = F_55 () ;
struct V_8 * V_9 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 ) {
V_9 = F_16 ( V_13 ) ;
F_82 ( V_9 , V_80 ) ;
}
}
static int F_84 ( void )
{
const int V_40 = F_55 () ;
struct V_8 * V_9 ;
struct V_7 * V_12 ;
int V_13 ;
int V_81 ;
V_81 = 0 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 ) {
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_36 )
continue;
V_81 ++ ;
}
return V_81 ;
}
static int F_85 ( void )
{
const int V_11 = F_86 () ;
struct V_2 * V_3 ;
struct V_1 * V_15 ;
struct V_7 * V_12 ;
int V_13 ;
int V_82 ;
V_82 = 0 ;
for ( V_13 = 0 ; V_13 < V_11 ; ++ V_13 ) {
V_3 = F_87 ( V_13 ) ;
V_15 = F_1 ( V_3 ) ;
if ( ! V_15 -> V_36 && ! V_15 -> V_38 )
continue;
V_12 = F_2 ( V_3 -> V_27 ) ;
if ( ! V_12 -> V_36 )
continue;
V_82 ++ ;
}
return V_82 ;
}
static bool F_88 ( void )
{
int V_81 = F_84 () ;
int V_82 = F_85 () ;
if ( ! F_6 ( V_83 ) )
return false ;
return V_81 <= 1 && V_82 <= 1 ;
}
int F_89 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
int V_49 ;
bool V_70 ;
F_90 ( & V_84 ) ;
if ( V_12 -> V_36 )
goto V_85;
F_20 ( & V_14 , V_47 ) ;
V_12 -> V_36 = true ;
V_49 = F_12 ( V_9 ) ;
if ( V_49 ) {
F_26 ( L_14 ,
V_9 -> V_6 ) ;
goto V_86;
}
V_70 = F_88 () ;
F_83 ( V_70 ) ;
F_79 ( V_70 ) ;
F_57 () ;
F_58 () ;
F_21 ( & V_14 , V_47 ) ;
F_19 () ;
F_20 ( & V_14 , V_47 ) ;
if ( ! F_8 ( V_9 ) )
V_12 -> V_41 = true ;
F_21 ( & V_14 , V_47 ) ;
if ( ! F_8 ( V_9 ) )
F_63 ( V_9 -> V_6 , true ) ;
V_85:
F_91 ( & V_84 ) ;
return 0 ;
V_86:
V_12 -> V_36 = false ;
F_21 ( & V_14 , V_47 ) ;
F_91 ( & V_84 ) ;
return V_49 ;
}
void F_92 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
bool V_70 ;
F_90 ( & V_84 ) ;
if ( ! V_12 -> V_36 )
goto V_85;
if ( ! F_8 ( V_9 ) )
F_63 ( V_9 -> V_6 , false ) ;
F_20 ( & V_14 , V_47 ) ;
V_12 -> V_41 = false ;
V_12 -> V_36 = false ;
V_70 = F_88 () ;
F_83 ( V_70 ) ;
F_79 ( V_70 ) ;
F_57 () ;
F_58 () ;
F_21 ( & V_14 , V_47 ) ;
F_19 () ;
V_85:
F_91 ( & V_84 ) ;
}
int F_93 ( struct V_8 * V_9 ,
struct V_32 * V_16 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
int V_49 ;
V_49 = F_94 ( V_9 , V_16 ) ;
if ( V_49 )
return V_49 ;
F_20 ( & V_14 , V_47 ) ;
V_12 -> V_20 = * V_16 ;
V_12 -> V_37 = true ;
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
void F_95 ( struct V_8 * V_9 ,
struct V_32 * V_16 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
F_20 ( & V_14 , V_47 ) ;
* V_16 = V_12 -> V_20 ;
F_21 ( & V_14 , V_47 ) ;
}
int F_96 ( struct V_8 * V_9 ,
struct V_53 * V_54 )
{
int V_49 ;
F_90 ( & V_84 ) ;
if ( V_54 -> V_27 ) {
F_26 ( L_15 ,
V_54 -> V_71 , V_54 -> V_27 -> V_71 ) ;
V_49 = - V_87 ;
goto V_86;
}
if ( ( V_9 -> V_88 & V_54 -> type ) == 0 ) {
F_26 ( L_16 ,
V_54 -> V_71 , V_9 -> V_71 ) ;
V_49 = - V_87 ;
goto V_86;
}
V_54 -> V_27 = V_9 ;
V_9 -> V_55 = V_54 ;
F_91 ( & V_84 ) ;
return 0 ;
V_86:
F_91 ( & V_84 ) ;
return V_49 ;
}
int F_97 ( struct V_8 * V_9 )
{
int V_49 ;
F_90 ( & V_84 ) ;
if ( ! V_9 -> V_55 ) {
F_26 ( L_17 ) ;
V_49 = - V_87 ;
goto V_86;
}
if ( V_9 -> V_55 -> V_56 != V_89 ) {
V_49 = - V_87 ;
goto V_86;
}
V_9 -> V_55 -> V_27 = NULL ;
V_9 -> V_55 = NULL ;
F_91 ( & V_84 ) ;
return 0 ;
V_86:
F_91 ( & V_84 ) ;
return V_49 ;
}
static void F_98 ( struct V_8 * V_9 ,
struct V_90 * V_39 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
V_12 -> V_39 = * V_39 ;
V_12 -> V_45 = true ;
}
void F_99 ( struct V_8 * V_9 ,
struct V_90 * V_39 )
{
unsigned long V_47 ;
F_90 ( & V_84 ) ;
F_20 ( & V_14 , V_47 ) ;
F_98 ( V_9 , V_39 ) ;
F_57 () ;
F_58 () ;
F_21 ( & V_14 , V_47 ) ;
F_19 () ;
F_91 ( & V_84 ) ;
}
static void F_100 ( struct V_8 * V_9 ,
const struct V_91 * V_92 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
V_12 -> V_22 = * V_92 ;
V_12 -> V_45 = true ;
}
void F_101 ( struct V_8 * V_9 ,
const struct V_91 * V_92 )
{
unsigned long V_47 ;
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_90 ( & V_84 ) ;
if ( V_12 -> V_36 ) {
F_26 ( L_18 ,
V_9 -> V_71 ) ;
goto V_85;
}
F_20 ( & V_14 , V_47 ) ;
F_100 ( V_9 , V_92 ) ;
F_57 () ;
F_58 () ;
F_21 ( & V_14 , V_47 ) ;
F_19 () ;
V_85:
F_91 ( & V_84 ) ;
}
int F_102 ( struct V_2 * V_3 ,
struct V_30 * V_16 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
V_49 = F_103 ( V_3 , V_16 ) ;
if ( V_49 )
return V_49 ;
F_20 ( & V_14 , V_47 ) ;
V_15 -> V_20 = * V_16 ;
V_15 -> V_37 = true ;
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
void F_104 ( struct V_2 * V_3 ,
struct V_30 * V_16 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
F_20 ( & V_14 , V_47 ) ;
* V_16 = V_15 -> V_20 ;
F_21 ( & V_14 , V_47 ) ;
}
int F_105 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
if ( ! V_9 )
return - V_87 ;
F_90 ( & V_84 ) ;
if ( V_3 -> V_27 ) {
F_26 ( L_19 ,
V_3 -> V_71 , V_3 -> V_27 -> V_71 ) ;
V_49 = - V_87 ;
goto V_86;
}
F_20 ( & V_14 , V_47 ) ;
if ( V_15 -> V_36 ) {
F_21 ( & V_14 , V_47 ) ;
F_26 ( L_20 ) ;
V_49 = - V_87 ;
goto V_86;
}
V_15 -> V_63 = V_9 -> V_6 ;
V_15 -> V_45 = true ;
V_3 -> V_27 = V_9 ;
F_106 ( & V_3 -> V_93 , & V_9 -> V_94 ) ;
F_21 ( & V_14 , V_47 ) ;
F_91 ( & V_84 ) ;
return 0 ;
V_86:
F_91 ( & V_84 ) ;
return V_49 ;
}
int F_107 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
F_90 ( & V_84 ) ;
if ( ! V_3 -> V_27 ) {
F_26 ( L_21 ) ;
V_49 = - V_87 ;
goto V_86;
}
F_20 ( & V_14 , V_47 ) ;
if ( V_15 -> V_36 ) {
F_21 ( & V_14 , V_47 ) ;
F_26 ( L_22 ) ;
V_49 = - V_87 ;
goto V_86;
}
V_15 -> V_63 = - 1 ;
V_3 -> V_27 = NULL ;
F_108 ( & V_3 -> V_93 ) ;
F_21 ( & V_14 , V_47 ) ;
F_91 ( & V_84 ) ;
return 0 ;
V_86:
F_91 ( & V_84 ) ;
return V_49 ;
}
bool F_109 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
bool V_95 ;
F_20 ( & V_14 , V_47 ) ;
V_95 = V_15 -> V_36 ;
F_21 ( & V_14 , V_47 ) ;
return V_95 ;
}
int F_110 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
bool V_70 ;
int V_49 ;
F_90 ( & V_84 ) ;
if ( V_15 -> V_36 ) {
V_49 = 0 ;
goto V_96;
}
if ( V_3 -> V_27 == NULL || V_3 -> V_27 -> V_55 == NULL ) {
V_49 = - V_87 ;
goto V_96;
}
F_20 ( & V_14 , V_47 ) ;
V_15 -> V_38 = true ;
V_49 = F_12 ( V_3 -> V_27 ) ;
if ( V_49 ) {
F_26 ( L_23 ,
V_3 -> V_6 ) ;
goto V_97;
}
V_70 = F_88 () ;
F_83 ( V_70 ) ;
F_79 ( V_70 ) ;
F_57 () ;
F_58 () ;
F_21 ( & V_14 , V_47 ) ;
F_19 () ;
F_20 ( & V_14 , V_47 ) ;
V_15 -> V_38 = false ;
F_77 ( V_3 , true ) ;
F_57 () ;
F_58 () ;
F_21 ( & V_14 , V_47 ) ;
F_19 () ;
F_91 ( & V_84 ) ;
return 0 ;
V_97:
V_15 -> V_38 = false ;
F_21 ( & V_14 , V_47 ) ;
V_96:
F_91 ( & V_84 ) ;
return V_49 ;
}
int F_111 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
bool V_70 ;
int V_49 ;
F_90 ( & V_84 ) ;
if ( ! V_15 -> V_36 ) {
V_49 = 0 ;
goto V_86;
}
if ( V_3 -> V_27 == NULL || V_3 -> V_27 -> V_55 == NULL ) {
V_49 = - V_87 ;
goto V_86;
}
F_20 ( & V_14 , V_47 ) ;
F_77 ( V_3 , false ) ;
F_57 () ;
F_58 () ;
F_21 ( & V_14 , V_47 ) ;
F_19 () ;
F_20 ( & V_14 , V_47 ) ;
V_70 = F_88 () ;
F_83 ( V_70 ) ;
F_79 ( V_70 ) ;
F_57 () ;
F_58 () ;
F_21 ( & V_14 , V_47 ) ;
F_19 () ;
F_91 ( & V_84 ) ;
return 0 ;
V_86:
F_91 ( & V_84 ) ;
return V_49 ;
}
