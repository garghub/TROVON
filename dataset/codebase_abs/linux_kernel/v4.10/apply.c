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
V_15 -> V_16 . V_17 = V_18 ;
V_15 -> V_16 . V_19 = V_20 ;
V_15 -> V_16 . V_21 = 255 ;
switch ( V_13 ) {
case 0 :
V_15 -> V_16 . V_22 = 0 ;
break;
case 1 :
V_15 -> V_16 . V_22 =
F_6 ( V_23 ) ? 3 : 0 ;
break;
case 2 :
V_15 -> V_16 . V_22 =
F_6 ( V_23 ) ? 2 : 0 ;
break;
case 3 :
V_15 -> V_16 . V_22 =
F_6 ( V_23 ) ? 1 : 0 ;
break;
}
V_15 -> V_24 = V_15 -> V_16 ;
}
V_12 = & V_4 . V_10 [ V_25 ] ;
V_12 -> V_26 . V_27 = 24 ;
V_12 -> V_26 . V_28 . V_29 = 1 ;
V_12 -> V_26 . V_28 . V_30 = 1 ;
}
static bool F_7 ( struct V_2 * V_3 )
{
struct V_7 * V_12 = F_2 ( V_3 -> V_31 ) ;
return V_12 -> V_26 . V_32 ;
}
static bool F_8 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
return V_12 -> V_26 . V_32 ;
}
static int F_9 ( struct V_8 * V_9 ,
bool V_33 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_2 * V_3 ;
struct V_34 * V_38 [ V_39 ] ;
struct V_1 * V_15 ;
struct V_7 * V_12 ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_40 )
return 0 ;
if ( V_33 && V_12 -> V_41 )
V_37 = & V_12 -> V_24 ;
else
V_37 = & V_12 -> V_16 ;
F_10 (ovl, &mgr->overlays, list) {
V_15 = F_1 ( V_3 ) ;
if ( ! V_15 -> V_40 && ! V_15 -> V_42 )
V_35 = NULL ;
else if ( V_33 && V_15 -> V_41 )
V_35 = & V_15 -> V_24 ;
else
V_35 = & V_15 -> V_16 ;
V_38 [ V_3 -> V_6 ] = V_35 ;
}
return F_11 ( V_9 , V_37 , & V_12 -> V_43 , & V_12 -> V_26 , V_38 ) ;
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
const int V_44 = F_15 () ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_44 ; ++ V_13 ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
struct V_2 * V_3 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_40 )
continue;
if ( F_8 ( V_9 ) ) {
if ( V_12 -> V_45 )
return true ;
} else {
if ( V_12 -> V_46 )
return true ;
if ( V_12 -> V_47 )
return true ;
if ( V_12 -> V_48 )
return true ;
if ( V_12 -> V_49 )
return true ;
if ( V_12 -> V_50 )
return true ;
F_10 (ovl, &mgr->overlays, list) {
struct V_1 * V_15 ;
V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_49 )
return true ;
if ( V_15 -> V_50 )
return true ;
if ( ! V_15 -> V_40 )
continue;
if ( V_15 -> V_47 )
return true ;
if ( V_15 -> V_48 )
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
if ( V_12 -> V_48 || V_12 -> V_50 )
return true ;
F_10 (ovl, &mgr->overlays, list) {
V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_48 || V_15 -> V_50 )
return true ;
}
return false ;
}
static bool F_18 ( void )
{
const int V_44 = F_15 () ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_44 ; ++ V_13 ) {
struct V_8 * V_9 ;
struct V_2 * V_3 ;
struct V_7 * V_12 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_40 )
continue;
if ( ! V_12 -> V_45 )
continue;
if ( V_12 -> V_49 || V_12 -> V_50 )
return true ;
F_10 (ovl, &mgr->overlays, list) {
struct V_1 * V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_49 || V_15 -> V_50 )
return true ;
}
}
return false ;
}
static void F_19 ( void )
{
bool V_45 ;
unsigned long V_51 ;
unsigned long V_52 ;
int V_53 ;
F_20 ( & V_14 , V_51 ) ;
V_45 = F_18 () ;
if ( ! V_45 ) {
F_21 ( & V_14 , V_51 ) ;
return;
}
F_22 ( & V_54 ) ;
F_21 ( & V_14 , V_51 ) ;
V_52 = F_23 ( 500 ) ;
V_53 = F_24 ( & V_54 , V_52 ) ;
if ( V_53 == 0 )
F_25 ( L_1 ) ;
}
static struct V_55 * F_26 ( struct V_8 * V_9 )
{
struct V_55 * V_56 ;
V_56 = V_9 -> V_57 ;
if ( V_56 == NULL )
return NULL ;
while ( V_56 -> V_58 )
V_56 = V_56 -> V_58 ;
if ( V_56 -> V_59 )
return V_56 ;
else
return NULL ;
}
static struct V_55 * F_27 ( struct V_2 * V_3 )
{
return V_3 -> V_31 ? F_26 ( V_3 -> V_31 ) : NULL ;
}
static int F_28 ( struct V_8 * V_9 )
{
unsigned long V_60 = F_23 ( 500 ) ;
T_1 V_61 ;
int V_53 ;
if ( V_9 -> V_57 == NULL )
return - V_62 ;
V_53 = F_29 () ;
if ( V_53 )
return V_53 ;
switch ( V_9 -> V_57 -> V_6 ) {
case V_63 :
V_61 = V_64 ;
break;
case V_65 :
V_61 = V_66 ;
break;
default:
V_61 = F_30 ( V_9 -> V_6 ) ;
break;
}
V_53 = F_31 ( V_61 , V_60 ) ;
F_32 () ;
return V_53 ;
}
static int F_33 ( struct V_8 * V_9 )
{
unsigned long V_60 = F_23 ( 500 ) ;
struct V_7 * V_12 = F_2 ( V_9 ) ;
T_1 V_61 ;
unsigned long V_51 ;
int V_53 ;
int V_13 ;
F_20 ( & V_14 , V_51 ) ;
if ( F_8 ( V_9 ) ) {
F_21 ( & V_14 , V_51 ) ;
return 0 ;
}
if ( ! V_12 -> V_40 ) {
F_21 ( & V_14 , V_51 ) ;
return 0 ;
}
F_21 ( & V_14 , V_51 ) ;
V_53 = F_29 () ;
if ( V_53 )
return V_53 ;
V_61 = F_30 ( V_9 -> V_6 ) ;
V_13 = 0 ;
while ( 1 ) {
bool V_67 , V_68 ;
F_20 ( & V_14 , V_51 ) ;
V_68 = V_12 -> V_47 ;
V_67 = V_12 -> V_48 ;
F_21 ( & V_14 , V_51 ) ;
if ( ! V_68 && ! V_67 ) {
V_53 = 0 ;
break;
}
if ( V_13 ++ == 3 ) {
F_34 ( L_2 ,
V_9 -> V_6 ) ;
V_53 = 0 ;
break;
}
V_53 = F_31 ( V_61 , V_60 ) ;
if ( V_53 == - V_69 )
break;
if ( V_53 ) {
F_34 ( L_3 , V_9 -> V_6 ) ;
break;
}
}
F_32 () ;
return V_53 ;
}
static int F_35 ( struct V_2 * V_3 )
{
unsigned long V_60 = F_23 ( 500 ) ;
struct V_1 * V_15 ;
struct V_7 * V_12 ;
T_1 V_61 ;
unsigned long V_51 ;
int V_53 ;
int V_13 ;
if ( ! V_3 -> V_31 )
return 0 ;
V_12 = F_2 ( V_3 -> V_31 ) ;
F_20 ( & V_14 , V_51 ) ;
if ( F_7 ( V_3 ) ) {
F_21 ( & V_14 , V_51 ) ;
return 0 ;
}
if ( ! V_12 -> V_40 ) {
F_21 ( & V_14 , V_51 ) ;
return 0 ;
}
F_21 ( & V_14 , V_51 ) ;
V_53 = F_29 () ;
if ( V_53 )
return V_53 ;
V_61 = F_30 ( V_3 -> V_31 -> V_6 ) ;
V_15 = F_1 ( V_3 ) ;
V_13 = 0 ;
while ( 1 ) {
bool V_67 , V_68 ;
F_20 ( & V_14 , V_51 ) ;
V_68 = V_15 -> V_47 ;
V_67 = V_15 -> V_48 ;
F_21 ( & V_14 , V_51 ) ;
if ( ! V_68 && ! V_67 ) {
V_53 = 0 ;
break;
}
if ( V_13 ++ == 3 ) {
F_34 ( L_4 ,
V_3 -> V_6 ) ;
V_53 = 0 ;
break;
}
V_53 = F_31 ( V_61 , V_60 ) ;
if ( V_53 == - V_69 )
break;
if ( V_53 ) {
F_34 ( L_5 , V_3 -> V_6 ) ;
break;
}
}
F_32 () ;
return V_53 ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_34 * V_35 ;
bool V_70 ;
struct V_7 * V_12 ;
int V_53 ;
F_37 ( L_6 , V_3 -> V_6 ) ;
if ( ! V_15 -> V_40 || ! V_15 -> V_47 )
return;
V_35 = & V_15 -> V_16 ;
V_12 = F_2 ( V_3 -> V_31 ) ;
V_70 = F_38 ( V_12 -> V_26 , V_35 -> V_17 ) ;
V_53 = F_39 ( V_3 -> V_6 , V_35 , V_70 , & V_12 -> V_43 , false ) ;
if ( V_53 ) {
F_34 ( L_7 , V_3 -> V_6 ) ;
V_15 -> V_40 = false ;
F_40 ( V_3 -> V_6 , false ) ;
return;
}
V_15 -> V_47 = false ;
if ( V_12 -> V_45 )
V_15 -> V_48 = true ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_7 * V_12 ;
F_37 ( L_8 , V_3 -> V_6 ) ;
if ( ! V_15 -> V_49 )
return;
F_40 ( V_3 -> V_6 , V_15 -> V_40 ) ;
F_42 ( V_3 -> V_6 , V_15 -> V_71 , V_15 -> V_72 ) ;
V_12 = F_2 ( V_3 -> V_31 ) ;
V_15 -> V_49 = false ;
if ( V_12 -> V_45 )
V_15 -> V_50 = true ;
}
static void F_43 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
struct V_2 * V_3 ;
F_37 ( L_9 , V_9 -> V_6 ) ;
if ( ! V_12 -> V_40 )
return;
F_44 ( V_12 -> V_46 ) ;
F_10 (ovl, &mgr->overlays, list) {
F_36 ( V_3 ) ;
F_41 ( V_3 ) ;
}
if ( V_12 -> V_47 ) {
F_45 ( V_9 -> V_6 , & V_12 -> V_16 ) ;
V_12 -> V_47 = false ;
if ( V_12 -> V_45 )
V_12 -> V_48 = true ;
}
}
static void F_46 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_37 ( L_10 , V_9 -> V_6 ) ;
if ( ! V_12 -> V_49 )
return;
F_47 ( V_9 -> V_6 , & V_12 -> V_43 ) ;
if ( F_48 ( V_9 -> V_6 ) )
F_49 ( V_9 -> V_6 , & V_12 -> V_26 ) ;
V_12 -> V_49 = false ;
if ( V_12 -> V_45 )
V_12 -> V_50 = true ;
}
static void F_50 ( void )
{
const int V_44 = F_51 () ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_44 ; ++ V_13 ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
int V_53 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_40 || F_8 ( V_9 ) || V_12 -> V_46 )
continue;
V_53 = F_12 ( V_9 ) ;
if ( V_53 ) {
F_34 ( L_11
L_12 , V_9 -> V_73 ) ;
continue;
}
F_43 ( V_9 ) ;
F_46 ( V_9 ) ;
}
}
static void F_52 ( void )
{
const int V_44 = F_51 () ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_44 ; ++ V_13 ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_40 || F_8 ( V_9 ) || V_12 -> V_46 )
continue;
if ( ! F_17 ( V_9 ) )
continue;
V_12 -> V_46 = true ;
if ( ! V_4 . V_74 && F_14 () )
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
V_12 -> V_48 = false ;
V_12 -> V_50 = false ;
F_10 (ovl, &mgr->overlays, list) {
V_15 = F_1 ( V_3 ) ;
V_15 -> V_48 = false ;
V_15 -> V_50 = false ;
}
}
static int F_56 ( struct V_8 * V_9 ,
struct V_55 * V_58 )
{
return V_9 -> V_75 ( V_9 , V_58 ) ;
}
static void F_57 ( struct V_8 * V_9 ,
struct V_55 * V_58 )
{
V_9 -> V_76 ( V_9 ) ;
}
static void F_58 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_51 ;
int V_53 ;
F_20 ( & V_14 , V_51 ) ;
F_44 ( V_12 -> V_45 ) ;
V_53 = F_12 ( V_9 ) ;
if ( V_53 ) {
F_34 ( L_13 ) ;
F_21 ( & V_14 , V_51 ) ;
return;
}
F_43 ( V_9 ) ;
F_46 ( V_9 ) ;
V_12 -> V_45 = true ;
if ( ! V_4 . V_74 && F_14 () )
F_53 () ;
F_59 ( V_9 -> V_6 ) ;
F_21 ( & V_14 , V_51 ) ;
}
static void F_53 ( void )
{
const int V_44 = F_15 () ;
T_1 V_77 ;
int V_53 , V_13 ;
V_77 = 0 ;
for ( V_13 = 0 ; V_13 < V_44 ; ++ V_13 )
V_77 |= F_30 ( V_13 ) ;
for ( V_13 = 0 ; V_13 < V_44 ; ++ V_13 )
V_77 |= F_60 ( V_13 ) ;
V_53 = F_61 ( V_78 , NULL , V_77 ) ;
F_44 ( V_53 ) ;
V_4 . V_74 = true ;
}
static void F_62 ( void )
{
const int V_44 = F_15 () ;
T_1 V_77 ;
int V_53 , V_13 ;
V_77 = 0 ;
for ( V_13 = 0 ; V_13 < V_44 ; ++ V_13 )
V_77 |= F_30 ( V_13 ) ;
for ( V_13 = 0 ; V_13 < V_44 ; ++ V_13 )
V_77 |= F_60 ( V_13 ) ;
V_53 = F_63 ( V_78 , NULL , V_77 ) ;
F_44 ( V_53 ) ;
V_4 . V_74 = false ;
}
static void V_78 ( void * V_79 , T_1 V_77 )
{
const int V_44 = F_15 () ;
int V_13 ;
bool V_80 ;
F_64 ( & V_14 ) ;
for ( V_13 = 0 ; V_13 < V_44 ; V_13 ++ ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_40 )
continue;
V_12 -> V_45 = F_65 ( V_13 ) ;
if ( ! F_8 ( V_9 ) ) {
bool V_81 = V_12 -> V_46 ;
V_12 -> V_46 = F_66 ( V_13 ) ;
if ( V_81 && ! V_12 -> V_46 )
F_55 ( V_9 ) ;
}
}
F_50 () ;
F_52 () ;
V_80 = F_18 () ;
if ( ! V_80 )
F_67 ( & V_54 ) ;
for ( V_13 = 0 ; V_13 < V_44 ; V_13 ++ ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! F_8 ( V_9 ) || ! V_12 -> V_82 )
continue;
if ( V_77 & F_60 ( V_13 ) )
V_12 -> V_82 ( V_12 -> V_83 ) ;
}
if ( ! F_14 () )
F_62 () ;
F_68 ( & V_14 ) ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_15 ;
V_15 = F_1 ( V_3 ) ;
if ( ! V_15 -> V_41 )
return;
V_15 -> V_41 = false ;
V_15 -> V_47 = true ;
V_15 -> V_16 = V_15 -> V_24 ;
}
static void F_70 ( struct V_8 * V_9 )
{
struct V_7 * V_12 ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_41 )
return;
V_12 -> V_41 = false ;
V_12 -> V_47 = true ;
V_12 -> V_16 = V_12 -> V_24 ;
}
static int F_71 ( struct V_8 * V_9 )
{
unsigned long V_51 ;
struct V_2 * V_3 ;
int V_53 ;
F_37 ( L_14 , V_9 -> V_73 ) ;
F_20 ( & V_14 , V_51 ) ;
V_53 = F_13 ( V_9 ) ;
if ( V_53 ) {
F_21 ( & V_14 , V_51 ) ;
F_34 ( L_15 ) ;
return V_53 ;
}
F_10 (ovl, &mgr->overlays, list)
F_69 ( V_3 ) ;
F_70 ( V_9 ) ;
F_50 () ;
F_52 () ;
F_21 ( & V_14 , V_51 ) ;
return 0 ;
}
static void F_72 ( struct V_2 * V_3 , bool V_84 )
{
struct V_1 * V_15 ;
V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_40 == V_84 )
return;
V_15 -> V_40 = V_84 ;
V_15 -> V_49 = true ;
}
static void F_73 ( struct V_2 * V_3 ,
T_1 V_71 , T_1 V_72 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_71 == V_71 && V_15 -> V_72 == V_72 )
return;
V_15 -> V_71 = V_71 ;
V_15 -> V_72 = V_72 ;
V_15 -> V_49 = true ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
T_1 V_71 , V_72 ;
bool V_85 = false ;
if ( ! V_15 -> V_40 && ! V_15 -> V_42 )
return;
F_75 ( V_3 -> V_6 , & V_71 , & V_72 ,
V_85 , F_7 ( V_3 ) ) ;
F_73 ( V_3 , V_71 , V_72 ) ;
}
static void F_76 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_7 * V_12 ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_40 )
return;
F_10 (ovl, &mgr->overlays, list)
F_74 ( V_3 ) ;
}
static void F_77 ( void )
{
const int V_44 = F_51 () ;
struct V_8 * V_9 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_44 ; ++ V_13 ) {
V_9 = F_16 ( V_13 ) ;
F_76 ( V_9 ) ;
}
}
static int F_78 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_51 ;
int V_53 ;
F_79 ( & V_86 ) ;
if ( V_12 -> V_40 )
goto V_87;
F_20 ( & V_14 , V_51 ) ;
V_12 -> V_40 = true ;
V_53 = F_12 ( V_9 ) ;
if ( V_53 ) {
F_34 ( L_16 ,
V_9 -> V_6 ) ;
goto V_88;
}
F_77 () ;
F_50 () ;
F_52 () ;
if ( ! F_8 ( V_9 ) )
V_12 -> V_45 = true ;
if ( ! V_4 . V_74 && F_14 () )
F_53 () ;
F_21 ( & V_14 , V_51 ) ;
if ( ! F_8 ( V_9 ) )
F_59 ( V_9 -> V_6 ) ;
V_87:
F_80 ( & V_86 ) ;
return 0 ;
V_88:
V_12 -> V_40 = false ;
F_21 ( & V_14 , V_51 ) ;
F_80 ( & V_86 ) ;
return V_53 ;
}
static void F_81 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_51 ;
F_79 ( & V_86 ) ;
if ( ! V_12 -> V_40 )
goto V_87;
F_19 () ;
if ( ! F_8 ( V_9 ) )
F_82 ( V_9 -> V_6 ) ;
F_20 ( & V_14 , V_51 ) ;
V_12 -> V_45 = false ;
V_12 -> V_40 = false ;
F_21 ( & V_14 , V_51 ) ;
V_87:
F_80 ( & V_86 ) ;
}
static int F_83 ( struct V_8 * V_9 ,
struct V_36 * V_16 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_51 ;
int V_53 ;
V_53 = F_84 ( V_9 , V_16 ) ;
if ( V_53 )
return V_53 ;
F_20 ( & V_14 , V_51 ) ;
V_12 -> V_24 = * V_16 ;
V_12 -> V_41 = true ;
F_21 ( & V_14 , V_51 ) ;
return 0 ;
}
static void F_85 ( struct V_8 * V_9 ,
struct V_36 * V_16 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_51 ;
F_20 ( & V_14 , V_51 ) ;
* V_16 = V_12 -> V_24 ;
F_21 ( & V_14 , V_51 ) ;
}
static int F_86 ( struct V_8 * V_9 ,
struct V_55 * V_57 )
{
int V_53 ;
F_79 ( & V_86 ) ;
if ( V_9 -> V_57 ) {
F_34 ( L_17 ,
V_9 -> V_73 ) ;
V_53 = - V_89 ;
goto V_88;
}
if ( ( V_9 -> V_90 & V_57 -> V_6 ) == 0 ) {
F_34 ( L_18 ,
V_9 -> V_73 ) ;
V_53 = - V_89 ;
goto V_88;
}
V_57 -> V_31 = V_9 ;
V_9 -> V_57 = V_57 ;
F_80 ( & V_86 ) ;
return 0 ;
V_88:
F_80 ( & V_86 ) ;
return V_53 ;
}
static int F_87 ( struct V_8 * V_9 )
{
int V_53 ;
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_51 ;
F_79 ( & V_86 ) ;
if ( ! V_9 -> V_57 ) {
F_34 ( L_19 ) ;
V_53 = - V_89 ;
goto V_88;
}
F_20 ( & V_14 , V_51 ) ;
if ( V_12 -> V_40 ) {
F_34 ( L_20 ) ;
V_53 = - V_89 ;
goto V_91;
}
F_21 ( & V_14 , V_51 ) ;
V_9 -> V_57 -> V_31 = NULL ;
V_9 -> V_57 = NULL ;
F_80 ( & V_86 ) ;
return 0 ;
V_91:
F_21 ( & V_14 , V_51 ) ;
V_88:
F_80 ( & V_86 ) ;
return V_53 ;
}
static void F_88 ( struct V_8 * V_9 ,
const struct V_92 * V_43 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
V_12 -> V_43 = * V_43 ;
V_12 -> V_49 = true ;
}
static void F_89 ( struct V_8 * V_9 ,
const struct V_92 * V_43 )
{
unsigned long V_51 ;
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_20 ( & V_14 , V_51 ) ;
if ( V_12 -> V_45 ) {
F_34 ( L_21 ,
V_9 -> V_73 ) ;
goto V_87;
}
F_88 ( V_9 , V_43 ) ;
V_87:
F_21 ( & V_14 , V_51 ) ;
}
static void F_90 ( struct V_8 * V_9 ,
const struct V_93 * V_94 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
V_12 -> V_26 = * V_94 ;
V_12 -> V_49 = true ;
}
static void F_91 ( struct V_8 * V_9 ,
const struct V_93 * V_94 )
{
unsigned long V_51 ;
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_20 ( & V_14 , V_51 ) ;
if ( V_12 -> V_40 ) {
F_34 ( L_22 ,
V_9 -> V_73 ) ;
goto V_87;
}
F_90 ( V_9 , V_94 ) ;
V_87:
F_21 ( & V_14 , V_51 ) ;
}
static int F_92 ( struct V_2 * V_3 ,
struct V_34 * V_16 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_51 ;
int V_53 ;
V_53 = F_93 ( V_3 , V_16 ) ;
if ( V_53 )
return V_53 ;
F_20 ( & V_14 , V_51 ) ;
V_15 -> V_24 = * V_16 ;
V_15 -> V_41 = true ;
F_21 ( & V_14 , V_51 ) ;
return 0 ;
}
static void F_94 ( struct V_2 * V_3 ,
struct V_34 * V_16 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_51 ;
F_20 ( & V_14 , V_51 ) ;
* V_16 = V_15 -> V_24 ;
F_21 ( & V_14 , V_51 ) ;
}
static int F_95 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_51 ;
int V_53 ;
if ( ! V_9 )
return - V_89 ;
F_79 ( & V_86 ) ;
if ( V_3 -> V_31 ) {
F_34 ( L_23 ,
V_3 -> V_73 , V_3 -> V_31 -> V_73 ) ;
V_53 = - V_89 ;
goto V_88;
}
V_53 = F_29 () ;
if ( V_53 )
goto V_88;
F_20 ( & V_14 , V_51 ) ;
if ( V_15 -> V_40 ) {
F_21 ( & V_14 , V_51 ) ;
F_34 ( L_24 ) ;
V_53 = - V_89 ;
goto V_91;
}
F_96 ( V_3 -> V_6 , V_9 -> V_6 ) ;
V_3 -> V_31 = V_9 ;
F_97 ( & V_3 -> V_95 , & V_9 -> V_96 ) ;
F_21 ( & V_14 , V_51 ) ;
F_32 () ;
F_80 ( & V_86 ) ;
return 0 ;
V_91:
F_32 () ;
V_88:
F_80 ( & V_86 ) ;
return V_53 ;
}
static int F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_51 ;
int V_53 ;
F_79 ( & V_86 ) ;
if ( ! V_3 -> V_31 ) {
F_34 ( L_25 ) ;
V_53 = - V_89 ;
goto V_88;
}
F_20 ( & V_14 , V_51 ) ;
if ( V_15 -> V_40 ) {
F_21 ( & V_14 , V_51 ) ;
F_34 ( L_26 ) ;
V_53 = - V_89 ;
goto V_88;
}
F_21 ( & V_14 , V_51 ) ;
F_19 () ;
F_20 ( & V_14 , V_51 ) ;
if ( F_7 ( V_3 ) && V_15 -> V_49 ) {
F_21 ( & V_14 , V_51 ) ;
F_34 ( L_27 ) ;
V_53 = - V_89 ;
goto V_88;
}
V_3 -> V_31 = NULL ;
F_99 ( & V_3 -> V_95 ) ;
F_21 ( & V_14 , V_51 ) ;
F_80 ( & V_86 ) ;
return 0 ;
V_88:
F_80 ( & V_86 ) ;
return V_53 ;
}
static bool F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_51 ;
bool V_97 ;
F_20 ( & V_14 , V_51 ) ;
V_97 = V_15 -> V_40 ;
F_21 ( & V_14 , V_51 ) ;
return V_97 ;
}
static int F_101 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_51 ;
int V_53 ;
F_79 ( & V_86 ) ;
if ( V_15 -> V_40 ) {
V_53 = 0 ;
goto V_91;
}
if ( V_3 -> V_31 == NULL || V_3 -> V_31 -> V_57 == NULL ) {
V_53 = - V_89 ;
goto V_91;
}
F_20 ( & V_14 , V_51 ) ;
V_15 -> V_42 = true ;
V_53 = F_12 ( V_3 -> V_31 ) ;
if ( V_53 ) {
F_34 ( L_28 ,
V_3 -> V_6 ) ;
goto V_98;
}
F_77 () ;
V_15 -> V_42 = false ;
F_72 ( V_3 , true ) ;
F_50 () ;
F_52 () ;
F_21 ( & V_14 , V_51 ) ;
F_80 ( & V_86 ) ;
return 0 ;
V_98:
V_15 -> V_42 = false ;
F_21 ( & V_14 , V_51 ) ;
V_91:
F_80 ( & V_86 ) ;
return V_53 ;
}
static int F_102 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_51 ;
int V_53 ;
F_79 ( & V_86 ) ;
if ( ! V_15 -> V_40 ) {
V_53 = 0 ;
goto V_88;
}
if ( V_3 -> V_31 == NULL || V_3 -> V_31 -> V_57 == NULL ) {
V_53 = - V_89 ;
goto V_88;
}
F_20 ( & V_14 , V_51 ) ;
F_72 ( V_3 , false ) ;
F_50 () ;
F_52 () ;
F_21 ( & V_14 , V_51 ) ;
F_80 ( & V_86 ) ;
return 0 ;
V_88:
F_80 ( & V_86 ) ;
return V_53 ;
}
static int F_103 ( struct V_8 * V_9 ,
void (* F_104)( void * ) , void * V_79 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
if ( V_12 -> V_82 )
return - V_99 ;
V_12 -> V_82 = F_104 ;
V_12 -> V_83 = V_79 ;
return 0 ;
}
static void F_105 ( struct V_8 * V_9 ,
void (* F_104)( void * ) , void * V_79 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_44 ( V_12 -> V_82 != F_104 ||
V_12 -> V_83 != V_79 ) ;
V_12 -> V_82 = NULL ;
V_12 -> V_83 = NULL ;
}
int F_106 ( void )
{
struct V_100 * V_101 = F_107 () ;
int V_13 , V_53 ;
F_79 ( & V_102 ) ;
if ( V_103 ++ > 0 )
goto V_87;
F_3 () ;
F_108 ( V_101 ) ;
F_109 ( V_101 ) ;
for ( V_13 = 0 ; V_13 < F_51 () ; V_13 ++ ) {
struct V_8 * V_9 ;
V_9 = F_16 ( V_13 ) ;
V_9 -> V_75 = & F_86 ;
V_9 -> V_76 = & F_87 ;
V_9 -> V_104 = & F_71 ;
V_9 -> V_105 = & F_83 ;
V_9 -> V_106 = & F_85 ;
V_9 -> V_107 = & F_33 ;
V_9 -> V_108 = & F_28 ;
V_9 -> V_109 = & F_26 ;
}
for ( V_13 = 0 ; V_13 < F_110 () ; V_13 ++ ) {
struct V_2 * V_3 = F_111 ( V_13 ) ;
V_3 -> V_110 = & F_100 ;
V_3 -> V_84 = & F_101 ;
V_3 -> V_111 = & F_102 ;
V_3 -> V_112 = & F_95 ;
V_3 -> V_113 = & F_98 ;
V_3 -> V_114 = & F_92 ;
V_3 -> V_115 = & F_94 ;
V_3 -> V_107 = & F_35 ;
V_3 -> V_109 = & F_27 ;
}
V_53 = F_112 ( & V_116 ) ;
if ( V_53 )
goto V_117;
V_53 = F_113 ( V_101 ) ;
if ( V_53 )
goto V_118;
F_29 () ;
V_53 = F_114 () ;
if ( V_53 )
goto V_119;
F_32 () ;
V_87:
F_80 ( & V_102 ) ;
return 0 ;
V_119:
F_32 () ;
F_115 ( V_101 ) ;
V_118:
F_116 () ;
V_117:
F_117 ( V_101 ) ;
F_118 ( V_101 ) ;
V_103 -- ;
F_80 ( & V_102 ) ;
return V_53 ;
}
void F_119 ( void )
{
struct V_100 * V_101 = F_107 () ;
F_79 ( & V_102 ) ;
if ( -- V_103 > 0 )
goto V_87;
F_120 () ;
F_115 ( V_101 ) ;
F_116 () ;
F_117 ( V_101 ) ;
F_118 ( V_101 ) ;
V_87:
F_80 ( & V_102 ) ;
}
