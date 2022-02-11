static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & V_4 . V_5 [ V_3 -> V_6 ] ;
}
static struct V_7 * F_2 ( struct V_8 * V_9 )
{
return & V_4 . V_10 [ V_9 -> V_6 ] ;
}
static void F_3 ( void )
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
}
static struct V_51 * F_26 ( struct V_8 * V_9 )
{
struct V_51 * V_52 ;
V_52 = V_9 -> V_53 ;
if ( V_52 == NULL )
return NULL ;
while ( V_52 -> V_54 )
V_52 = V_52 -> V_54 ;
if ( V_52 -> V_55 )
return V_52 ;
else
return NULL ;
}
static struct V_51 * F_27 ( struct V_2 * V_3 )
{
return V_3 -> V_27 ? F_26 ( V_3 -> V_27 ) : NULL ;
}
static int F_28 ( struct V_8 * V_9 )
{
unsigned long V_56 = F_23 ( 500 ) ;
T_1 V_57 ;
int V_49 ;
if ( V_9 -> V_53 == NULL )
return - V_58 ;
V_49 = F_29 () ;
if ( V_49 )
return V_49 ;
switch ( V_9 -> V_53 -> V_6 ) {
case V_59 :
V_57 = V_60 ;
break;
case V_61 :
V_57 = V_62 ;
break;
default:
V_57 = F_30 ( V_9 -> V_6 ) ;
break;
}
V_49 = F_31 ( V_57 , V_56 ) ;
F_32 () ;
return V_49 ;
}
static int F_33 ( struct V_8 * V_9 )
{
unsigned long V_56 = F_23 ( 500 ) ;
struct V_7 * V_12 = F_2 ( V_9 ) ;
T_1 V_57 ;
unsigned long V_47 ;
int V_49 ;
int V_13 ;
F_20 ( & V_14 , V_47 ) ;
if ( F_8 ( V_9 ) ) {
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
if ( ! V_12 -> V_36 ) {
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
F_21 ( & V_14 , V_47 ) ;
V_49 = F_29 () ;
if ( V_49 )
return V_49 ;
V_57 = F_30 ( V_9 -> V_6 ) ;
V_13 = 0 ;
while ( 1 ) {
bool V_63 , V_64 ;
F_20 ( & V_14 , V_47 ) ;
V_64 = V_12 -> V_43 ;
V_63 = V_12 -> V_44 ;
F_21 ( & V_14 , V_47 ) ;
if ( ! V_64 && ! V_63 ) {
V_49 = 0 ;
break;
}
if ( V_13 ++ == 3 ) {
F_34 ( L_2 ,
V_9 -> V_6 ) ;
V_49 = 0 ;
break;
}
V_49 = F_31 ( V_57 , V_56 ) ;
if ( V_49 == - V_65 )
break;
if ( V_49 ) {
F_34 ( L_3 , V_9 -> V_6 ) ;
break;
}
}
F_32 () ;
return V_49 ;
}
static int F_35 ( struct V_2 * V_3 )
{
unsigned long V_56 = F_23 ( 500 ) ;
struct V_1 * V_15 ;
struct V_7 * V_12 ;
T_1 V_57 ;
unsigned long V_47 ;
int V_49 ;
int V_13 ;
if ( ! V_3 -> V_27 )
return 0 ;
V_12 = F_2 ( V_3 -> V_27 ) ;
F_20 ( & V_14 , V_47 ) ;
if ( F_7 ( V_3 ) ) {
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
if ( ! V_12 -> V_36 ) {
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
F_21 ( & V_14 , V_47 ) ;
V_49 = F_29 () ;
if ( V_49 )
return V_49 ;
V_57 = F_30 ( V_3 -> V_27 -> V_6 ) ;
V_15 = F_1 ( V_3 ) ;
V_13 = 0 ;
while ( 1 ) {
bool V_63 , V_64 ;
F_20 ( & V_14 , V_47 ) ;
V_64 = V_15 -> V_43 ;
V_63 = V_15 -> V_44 ;
F_21 ( & V_14 , V_47 ) ;
if ( ! V_64 && ! V_63 ) {
V_49 = 0 ;
break;
}
if ( V_13 ++ == 3 ) {
F_34 ( L_4 ,
V_3 -> V_6 ) ;
V_49 = 0 ;
break;
}
V_49 = F_31 ( V_57 , V_56 ) ;
if ( V_49 == - V_65 )
break;
if ( V_49 ) {
F_34 ( L_5 , V_3 -> V_6 ) ;
break;
}
}
F_32 () ;
return V_49 ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_30 * V_31 ;
bool V_66 ;
struct V_7 * V_12 ;
int V_49 ;
F_37 ( L_6 , V_3 -> V_6 ) ;
if ( ! V_15 -> V_36 || ! V_15 -> V_43 )
return;
V_31 = & V_15 -> V_16 ;
V_12 = F_2 ( V_3 -> V_27 ) ;
V_66 = F_38 ( V_12 -> V_22 , V_31 -> V_67 ) ;
V_49 = F_39 ( V_3 -> V_6 , V_31 , V_66 , & V_12 -> V_39 , false ) ;
if ( V_49 ) {
F_34 ( L_7 , V_3 -> V_6 ) ;
V_15 -> V_36 = false ;
F_40 ( V_3 -> V_6 , false ) ;
return;
}
V_15 -> V_43 = false ;
if ( V_12 -> V_41 )
V_15 -> V_44 = true ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_7 * V_12 ;
F_37 ( L_8 , V_3 -> V_6 ) ;
if ( ! V_15 -> V_45 )
return;
F_40 ( V_3 -> V_6 , V_15 -> V_36 ) ;
F_42 ( V_3 -> V_6 , V_15 -> V_68 , V_15 -> V_69 ) ;
V_12 = F_2 ( V_3 -> V_27 ) ;
V_15 -> V_45 = false ;
if ( V_12 -> V_41 )
V_15 -> V_46 = true ;
}
static void F_43 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
struct V_2 * V_3 ;
F_37 ( L_9 , V_9 -> V_6 ) ;
if ( ! V_12 -> V_36 )
return;
F_44 ( V_12 -> V_42 ) ;
F_10 (ovl, &mgr->overlays, list) {
F_36 ( V_3 ) ;
F_41 ( V_3 ) ;
}
if ( V_12 -> V_43 ) {
F_45 ( V_9 -> V_6 , & V_12 -> V_16 ) ;
V_12 -> V_43 = false ;
if ( V_12 -> V_41 )
V_12 -> V_44 = true ;
}
}
static void F_46 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_37 ( L_10 , V_9 -> V_6 ) ;
if ( ! V_12 -> V_45 )
return;
F_47 ( V_9 -> V_6 , & V_12 -> V_39 ) ;
if ( F_48 ( V_9 -> V_6 ) )
F_49 ( V_9 -> V_6 , & V_12 -> V_22 ) ;
V_12 -> V_45 = false ;
if ( V_12 -> V_41 )
V_12 -> V_46 = true ;
}
static void F_50 ( void )
{
const int V_40 = F_51 () ;
int V_13 ;
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
F_34 ( L_11
L_12 , V_9 -> V_70 ) ;
continue;
}
F_43 ( V_9 ) ;
F_46 ( V_9 ) ;
}
}
static void F_52 ( void )
{
const int V_40 = F_51 () ;
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
if ( ! V_4 . V_71 && F_14 () )
F_53 () ;
F_54 ( V_9 -> V_6 ) ;
}
}
static void F_55 ( struct V_8 * V_9 )
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
static int F_56 ( struct V_8 * V_9 ,
struct V_51 * V_54 )
{
return V_9 -> V_72 ( V_9 , V_54 ) ;
}
static void F_57 ( struct V_8 * V_9 ,
struct V_51 * V_54 )
{
V_9 -> V_73 ( V_9 ) ;
}
static void F_58 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
int V_49 ;
F_20 ( & V_14 , V_47 ) ;
F_44 ( V_12 -> V_41 ) ;
V_49 = F_12 ( V_9 ) ;
if ( V_49 ) {
F_34 ( L_13 ) ;
F_21 ( & V_14 , V_47 ) ;
return;
}
F_43 ( V_9 ) ;
F_46 ( V_9 ) ;
V_12 -> V_41 = true ;
if ( ! V_4 . V_71 && F_14 () )
F_53 () ;
F_59 ( V_9 -> V_6 ) ;
F_21 ( & V_14 , V_47 ) ;
}
static void F_53 ( void )
{
const int V_40 = F_15 () ;
T_1 V_74 ;
int V_49 , V_13 ;
V_74 = 0 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 )
V_74 |= F_30 ( V_13 ) ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 )
V_74 |= F_60 ( V_13 ) ;
V_49 = F_61 ( V_75 , NULL , V_74 ) ;
F_44 ( V_49 ) ;
V_4 . V_71 = true ;
}
static void F_62 ( void )
{
const int V_40 = F_15 () ;
T_1 V_74 ;
int V_49 , V_13 ;
V_74 = 0 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 )
V_74 |= F_30 ( V_13 ) ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 )
V_74 |= F_60 ( V_13 ) ;
V_49 = F_63 ( V_75 , NULL , V_74 ) ;
F_44 ( V_49 ) ;
V_4 . V_71 = false ;
}
static void V_75 ( void * V_76 , T_1 V_74 )
{
const int V_40 = F_15 () ;
int V_13 ;
bool V_77 ;
F_64 ( & V_14 ) ;
for ( V_13 = 0 ; V_13 < V_40 ; V_13 ++ ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_36 )
continue;
V_12 -> V_41 = F_65 ( V_13 ) ;
if ( ! F_8 ( V_9 ) ) {
bool V_78 = V_12 -> V_42 ;
V_12 -> V_42 = F_66 ( V_13 ) ;
if ( V_78 && ! V_12 -> V_42 )
F_55 ( V_9 ) ;
}
}
F_50 () ;
F_52 () ;
V_77 = F_18 () ;
if ( ! V_77 )
F_67 ( & V_50 ) ;
for ( V_13 = 0 ; V_13 < V_40 ; V_13 ++ ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! F_8 ( V_9 ) || ! V_12 -> V_79 )
continue;
if ( V_74 & F_60 ( V_13 ) )
V_12 -> V_79 ( V_12 -> V_80 ) ;
}
if ( ! F_14 () )
F_62 () ;
F_68 ( & V_14 ) ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_15 ;
V_15 = F_1 ( V_3 ) ;
if ( ! V_15 -> V_37 )
return;
V_15 -> V_37 = false ;
V_15 -> V_43 = true ;
V_15 -> V_16 = V_15 -> V_20 ;
}
static void F_70 ( struct V_8 * V_9 )
{
struct V_7 * V_12 ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_37 )
return;
V_12 -> V_37 = false ;
V_12 -> V_43 = true ;
V_12 -> V_16 = V_12 -> V_20 ;
}
static int F_71 ( struct V_8 * V_9 )
{
unsigned long V_47 ;
struct V_2 * V_3 ;
int V_49 ;
F_37 ( L_14 , V_9 -> V_70 ) ;
F_20 ( & V_14 , V_47 ) ;
V_49 = F_13 ( V_9 ) ;
if ( V_49 ) {
F_21 ( & V_14 , V_47 ) ;
F_34 ( L_15 ) ;
return V_49 ;
}
F_10 (ovl, &mgr->overlays, list)
F_69 ( V_3 ) ;
F_70 ( V_9 ) ;
F_50 () ;
F_52 () ;
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
static void F_72 ( struct V_2 * V_3 , bool V_81 )
{
struct V_1 * V_15 ;
V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_36 == V_81 )
return;
V_15 -> V_36 = V_81 ;
V_15 -> V_45 = true ;
}
static void F_73 ( struct V_2 * V_3 ,
T_1 V_68 , T_1 V_69 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_68 == V_68 && V_15 -> V_69 == V_69 )
return;
V_15 -> V_68 = V_68 ;
V_15 -> V_69 = V_69 ;
V_15 -> V_45 = true ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
T_1 V_68 , V_69 ;
bool V_82 = false ;
if ( ! V_15 -> V_36 && ! V_15 -> V_38 )
return;
F_75 ( V_3 -> V_6 , & V_68 , & V_69 ,
V_82 , F_7 ( V_3 ) ) ;
F_73 ( V_3 , V_68 , V_69 ) ;
}
static void F_76 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_7 * V_12 ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_36 )
return;
F_10 (ovl, &mgr->overlays, list)
F_74 ( V_3 ) ;
}
static void F_77 ( void )
{
const int V_40 = F_51 () ;
struct V_8 * V_9 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 ) {
V_9 = F_16 ( V_13 ) ;
F_76 ( V_9 ) ;
}
}
static int F_78 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
int V_49 ;
F_79 ( & V_83 ) ;
if ( V_12 -> V_36 )
goto V_84;
F_20 ( & V_14 , V_47 ) ;
V_12 -> V_36 = true ;
V_49 = F_12 ( V_9 ) ;
if ( V_49 ) {
F_34 ( L_16 ,
V_9 -> V_6 ) ;
goto V_85;
}
F_77 () ;
F_50 () ;
F_52 () ;
if ( ! F_8 ( V_9 ) )
V_12 -> V_41 = true ;
if ( ! V_4 . V_71 && F_14 () )
F_53 () ;
F_21 ( & V_14 , V_47 ) ;
if ( ! F_8 ( V_9 ) )
F_59 ( V_9 -> V_6 ) ;
V_84:
F_80 ( & V_83 ) ;
return 0 ;
V_85:
V_12 -> V_36 = false ;
F_21 ( & V_14 , V_47 ) ;
F_80 ( & V_83 ) ;
return V_49 ;
}
static void F_81 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
F_79 ( & V_83 ) ;
if ( ! V_12 -> V_36 )
goto V_84;
if ( ! F_8 ( V_9 ) )
F_82 ( V_9 -> V_6 ) ;
F_20 ( & V_14 , V_47 ) ;
V_12 -> V_41 = false ;
V_12 -> V_36 = false ;
F_21 ( & V_14 , V_47 ) ;
V_84:
F_80 ( & V_83 ) ;
}
static int F_83 ( struct V_8 * V_9 ,
struct V_32 * V_16 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
int V_49 ;
V_49 = F_84 ( V_9 , V_16 ) ;
if ( V_49 )
return V_49 ;
F_20 ( & V_14 , V_47 ) ;
V_12 -> V_20 = * V_16 ;
V_12 -> V_37 = true ;
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
static void F_85 ( struct V_8 * V_9 ,
struct V_32 * V_16 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
F_20 ( & V_14 , V_47 ) ;
* V_16 = V_12 -> V_20 ;
F_21 ( & V_14 , V_47 ) ;
}
static int F_86 ( struct V_8 * V_9 ,
struct V_51 * V_53 )
{
int V_49 ;
F_79 ( & V_83 ) ;
if ( V_9 -> V_53 ) {
F_34 ( L_17 ,
V_9 -> V_70 ) ;
V_49 = - V_86 ;
goto V_85;
}
if ( ( V_9 -> V_87 & V_53 -> V_6 ) == 0 ) {
F_34 ( L_18 ,
V_9 -> V_70 ) ;
V_49 = - V_86 ;
goto V_85;
}
V_53 -> V_27 = V_9 ;
V_9 -> V_53 = V_53 ;
F_80 ( & V_83 ) ;
return 0 ;
V_85:
F_80 ( & V_83 ) ;
return V_49 ;
}
static int F_87 ( struct V_8 * V_9 )
{
int V_49 ;
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
F_79 ( & V_83 ) ;
if ( ! V_9 -> V_53 ) {
F_34 ( L_19 ) ;
V_49 = - V_86 ;
goto V_85;
}
F_20 ( & V_14 , V_47 ) ;
if ( V_12 -> V_36 ) {
F_34 ( L_20 ) ;
V_49 = - V_86 ;
goto V_88;
}
F_21 ( & V_14 , V_47 ) ;
V_9 -> V_53 -> V_27 = NULL ;
V_9 -> V_53 = NULL ;
F_80 ( & V_83 ) ;
return 0 ;
V_88:
F_21 ( & V_14 , V_47 ) ;
V_85:
F_80 ( & V_83 ) ;
return V_49 ;
}
static void F_88 ( struct V_8 * V_9 ,
const struct V_89 * V_39 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
V_12 -> V_39 = * V_39 ;
V_12 -> V_45 = true ;
}
static void F_89 ( struct V_8 * V_9 ,
const struct V_89 * V_39 )
{
unsigned long V_47 ;
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_20 ( & V_14 , V_47 ) ;
if ( V_12 -> V_41 ) {
F_34 ( L_21 ,
V_9 -> V_70 ) ;
goto V_84;
}
F_88 ( V_9 , V_39 ) ;
V_84:
F_21 ( & V_14 , V_47 ) ;
}
static void F_90 ( struct V_8 * V_9 ,
const struct V_90 * V_91 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
V_12 -> V_22 = * V_91 ;
V_12 -> V_45 = true ;
}
static void F_91 ( struct V_8 * V_9 ,
const struct V_90 * V_91 )
{
unsigned long V_47 ;
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_20 ( & V_14 , V_47 ) ;
if ( V_12 -> V_36 ) {
F_34 ( L_22 ,
V_9 -> V_70 ) ;
goto V_84;
}
F_90 ( V_9 , V_91 ) ;
V_84:
F_21 ( & V_14 , V_47 ) ;
}
static int F_92 ( struct V_2 * V_3 ,
struct V_30 * V_16 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
V_49 = F_93 ( V_3 , V_16 ) ;
if ( V_49 )
return V_49 ;
F_20 ( & V_14 , V_47 ) ;
V_15 -> V_20 = * V_16 ;
V_15 -> V_37 = true ;
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
static void F_94 ( struct V_2 * V_3 ,
struct V_30 * V_16 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
F_20 ( & V_14 , V_47 ) ;
* V_16 = V_15 -> V_20 ;
F_21 ( & V_14 , V_47 ) ;
}
static int F_95 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
if ( ! V_9 )
return - V_86 ;
F_79 ( & V_83 ) ;
if ( V_3 -> V_27 ) {
F_34 ( L_23 ,
V_3 -> V_70 , V_3 -> V_27 -> V_70 ) ;
V_49 = - V_86 ;
goto V_85;
}
V_49 = F_29 () ;
if ( V_49 )
goto V_85;
F_20 ( & V_14 , V_47 ) ;
if ( V_15 -> V_36 ) {
F_21 ( & V_14 , V_47 ) ;
F_34 ( L_24 ) ;
V_49 = - V_86 ;
goto V_88;
}
F_96 ( V_3 -> V_6 , V_9 -> V_6 ) ;
V_3 -> V_27 = V_9 ;
F_97 ( & V_3 -> V_92 , & V_9 -> V_93 ) ;
F_21 ( & V_14 , V_47 ) ;
F_32 () ;
F_80 ( & V_83 ) ;
return 0 ;
V_88:
F_32 () ;
V_85:
F_80 ( & V_83 ) ;
return V_49 ;
}
static int F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
F_79 ( & V_83 ) ;
if ( ! V_3 -> V_27 ) {
F_34 ( L_25 ) ;
V_49 = - V_86 ;
goto V_85;
}
F_20 ( & V_14 , V_47 ) ;
if ( V_15 -> V_36 ) {
F_21 ( & V_14 , V_47 ) ;
F_34 ( L_26 ) ;
V_49 = - V_86 ;
goto V_85;
}
F_21 ( & V_14 , V_47 ) ;
F_19 () ;
F_20 ( & V_14 , V_47 ) ;
if ( F_7 ( V_3 ) && V_15 -> V_45 ) {
F_21 ( & V_14 , V_47 ) ;
F_34 ( L_27 ) ;
V_49 = - V_86 ;
goto V_85;
}
V_3 -> V_27 = NULL ;
F_99 ( & V_3 -> V_92 ) ;
F_21 ( & V_14 , V_47 ) ;
F_80 ( & V_83 ) ;
return 0 ;
V_85:
F_80 ( & V_83 ) ;
return V_49 ;
}
static bool F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
bool V_94 ;
F_20 ( & V_14 , V_47 ) ;
V_94 = V_15 -> V_36 ;
F_21 ( & V_14 , V_47 ) ;
return V_94 ;
}
static int F_101 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
F_79 ( & V_83 ) ;
if ( V_15 -> V_36 ) {
V_49 = 0 ;
goto V_88;
}
if ( V_3 -> V_27 == NULL || V_3 -> V_27 -> V_53 == NULL ) {
V_49 = - V_86 ;
goto V_88;
}
F_20 ( & V_14 , V_47 ) ;
V_15 -> V_38 = true ;
V_49 = F_12 ( V_3 -> V_27 ) ;
if ( V_49 ) {
F_34 ( L_28 ,
V_3 -> V_6 ) ;
goto V_95;
}
F_77 () ;
V_15 -> V_38 = false ;
F_72 ( V_3 , true ) ;
F_50 () ;
F_52 () ;
F_21 ( & V_14 , V_47 ) ;
F_80 ( & V_83 ) ;
return 0 ;
V_95:
V_15 -> V_38 = false ;
F_21 ( & V_14 , V_47 ) ;
V_88:
F_80 ( & V_83 ) ;
return V_49 ;
}
static int F_102 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
F_79 ( & V_83 ) ;
if ( ! V_15 -> V_36 ) {
V_49 = 0 ;
goto V_85;
}
if ( V_3 -> V_27 == NULL || V_3 -> V_27 -> V_53 == NULL ) {
V_49 = - V_86 ;
goto V_85;
}
F_20 ( & V_14 , V_47 ) ;
F_72 ( V_3 , false ) ;
F_50 () ;
F_52 () ;
F_21 ( & V_14 , V_47 ) ;
F_80 ( & V_83 ) ;
return 0 ;
V_85:
F_80 ( & V_83 ) ;
return V_49 ;
}
static int F_103 ( struct V_8 * V_9 ,
void (* F_104)( void * ) , void * V_76 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
if ( V_12 -> V_79 )
return - V_96 ;
V_12 -> V_79 = F_104 ;
V_12 -> V_80 = V_76 ;
return 0 ;
}
static void F_105 ( struct V_8 * V_9 ,
void (* F_104)( void * ) , void * V_76 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_44 ( V_12 -> V_79 != F_104 ||
V_12 -> V_80 != V_76 ) ;
V_12 -> V_79 = NULL ;
V_12 -> V_80 = NULL ;
}
int F_106 ( void )
{
struct V_97 * V_98 = F_107 () ;
int V_13 , V_49 ;
F_79 ( & V_99 ) ;
if ( V_100 ++ > 0 )
goto V_84;
F_3 () ;
F_108 ( V_98 ) ;
F_109 ( V_98 ) ;
for ( V_13 = 0 ; V_13 < F_51 () ; V_13 ++ ) {
struct V_8 * V_9 ;
V_9 = F_16 ( V_13 ) ;
V_9 -> V_72 = & F_86 ;
V_9 -> V_73 = & F_87 ;
V_9 -> V_101 = & F_71 ;
V_9 -> V_102 = & F_83 ;
V_9 -> V_103 = & F_85 ;
V_9 -> V_104 = & F_33 ;
V_9 -> V_105 = & F_28 ;
V_9 -> V_106 = & F_26 ;
}
for ( V_13 = 0 ; V_13 < F_110 () ; V_13 ++ ) {
struct V_2 * V_3 = F_111 ( V_13 ) ;
V_3 -> V_107 = & F_100 ;
V_3 -> V_81 = & F_101 ;
V_3 -> V_108 = & F_102 ;
V_3 -> V_109 = & F_95 ;
V_3 -> V_110 = & F_98 ;
V_3 -> V_111 = & F_92 ;
V_3 -> V_112 = & F_94 ;
V_3 -> V_104 = & F_35 ;
V_3 -> V_106 = & F_27 ;
}
V_49 = F_112 ( & V_113 ) ;
if ( V_49 )
goto V_114;
V_49 = F_113 ( V_98 ) ;
if ( V_49 )
goto V_115;
F_29 () ;
V_49 = F_114 () ;
if ( V_49 )
goto V_116;
F_32 () ;
V_84:
F_80 ( & V_99 ) ;
return 0 ;
V_116:
F_32 () ;
F_115 ( V_98 ) ;
V_115:
F_116 () ;
V_114:
F_117 ( V_98 ) ;
F_118 ( V_98 ) ;
V_100 -- ;
F_80 ( & V_99 ) ;
return V_49 ;
}
void F_119 ( void )
{
struct V_97 * V_98 = F_107 () ;
F_79 ( & V_99 ) ;
if ( -- V_100 > 0 )
goto V_84;
F_120 () ;
F_115 ( V_98 ) ;
F_116 () ;
F_117 ( V_98 ) ;
F_118 ( V_98 ) ;
V_84:
F_80 ( & V_99 ) ;
}
