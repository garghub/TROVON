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
int V_12 ;
F_5 ( & V_13 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; ++ V_12 ) {
struct V_1 * V_14 ;
V_14 = & V_4 . V_5 [ V_12 ] ;
V_14 -> V_15 . V_16 = 255 ;
switch ( V_12 ) {
case 0 :
V_14 -> V_15 . V_17 = 0 ;
break;
case 1 :
V_14 -> V_15 . V_17 =
F_6 ( V_18 ) ? 3 : 0 ;
break;
case 2 :
V_14 -> V_15 . V_17 =
F_6 ( V_18 ) ? 2 : 0 ;
break;
case 3 :
V_14 -> V_15 . V_17 =
F_6 ( V_18 ) ? 1 : 0 ;
break;
}
V_14 -> V_19 = V_14 -> V_15 ;
}
}
static bool F_7 ( struct V_2 * V_3 )
{
return V_3 -> V_20 -> V_21 -> V_22 & V_23 ;
}
static bool F_8 ( struct V_8 * V_9 )
{
return V_9 -> V_21 -> V_22 & V_23 ;
}
static int F_9 ( struct V_8 * V_9 ,
bool V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_2 * V_3 ;
struct V_25 * V_29 [ V_30 ] ;
struct V_1 * V_14 ;
struct V_7 * V_31 ;
V_31 = F_2 ( V_9 ) ;
if ( ! V_31 -> V_32 )
return 0 ;
if ( V_24 && V_31 -> V_33 )
V_28 = & V_31 -> V_19 ;
else
V_28 = & V_31 -> V_15 ;
F_10 (ovl, &mgr->overlays, list) {
V_14 = F_1 ( V_3 ) ;
if ( ! V_14 -> V_32 && ! V_14 -> V_34 )
V_26 = NULL ;
else if ( V_24 && V_14 -> V_33 )
V_26 = & V_14 -> V_19 ;
else
V_26 = & V_14 -> V_15 ;
V_29 [ V_3 -> V_6 ] = V_26 ;
}
return F_11 ( V_9 , V_28 , & V_31 -> V_35 , V_29 ) ;
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
const int V_36 = F_15 () ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 ) {
struct V_8 * V_9 ;
struct V_7 * V_31 ;
struct V_2 * V_3 ;
V_9 = F_16 ( V_12 ) ;
V_31 = F_2 ( V_9 ) ;
if ( ! V_31 -> V_32 )
continue;
if ( F_8 ( V_9 ) ) {
if ( V_31 -> V_37 )
return true ;
} else {
if ( V_31 -> V_38 )
return true ;
if ( V_31 -> V_39 )
return true ;
if ( V_31 -> V_40 )
return true ;
if ( V_31 -> V_41 )
return true ;
if ( V_31 -> V_42 )
return true ;
F_10 (ovl, &mgr->overlays, list) {
struct V_1 * V_14 ;
V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_41 )
return true ;
if ( V_14 -> V_42 )
return true ;
if ( ! V_14 -> V_32 )
continue;
if ( V_14 -> V_39 )
return true ;
if ( V_14 -> V_40 )
return true ;
}
}
}
return false ;
}
static bool F_17 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_7 * V_31 ;
struct V_1 * V_14 ;
V_31 = F_2 ( V_9 ) ;
if ( V_31 -> V_40 || V_31 -> V_42 )
return true ;
F_10 (ovl, &mgr->overlays, list) {
V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_40 || V_14 -> V_42 )
return true ;
}
return false ;
}
static bool F_18 ( void )
{
const int V_36 = F_15 () ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 ) {
struct V_8 * V_9 ;
struct V_2 * V_3 ;
struct V_7 * V_31 ;
V_9 = F_16 ( V_12 ) ;
V_31 = F_2 ( V_9 ) ;
if ( ! V_31 -> V_32 )
continue;
if ( ! V_31 -> V_37 )
continue;
if ( V_31 -> V_41 || V_31 -> V_42 )
return true ;
F_10 (ovl, &mgr->overlays, list) {
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_41 || V_14 -> V_42 )
return true ;
}
}
return false ;
}
static void F_19 ( void )
{
bool V_37 ;
unsigned long V_43 ;
unsigned long V_44 ;
int V_45 ;
F_20 ( & V_13 , V_43 ) ;
V_37 = F_18 () ;
if ( ! V_37 ) {
F_21 ( & V_13 , V_43 ) ;
return;
}
F_22 ( & V_46 ) ;
F_21 ( & V_13 , V_43 ) ;
V_44 = F_23 ( 500 ) ;
V_45 = F_24 ( & V_46 , V_44 ) ;
if ( V_45 == 0 )
F_25 ( L_1 ) ;
else if ( V_45 < 0 )
F_26 ( L_2 , V_45 ) ;
}
int F_27 ( struct V_8 * V_9 )
{
unsigned long V_47 = F_23 ( 500 ) ;
struct V_7 * V_31 ;
T_1 V_48 ;
int V_45 ;
int V_12 ;
struct V_49 * V_50 = V_9 -> V_21 ;
if ( ! V_50 || V_50 -> V_51 != V_52 )
return 0 ;
if ( F_8 ( V_9 ) )
return 0 ;
V_45 = F_28 () ;
if ( V_45 )
return V_45 ;
V_48 = F_29 ( V_9 -> V_6 ) ;
V_31 = F_2 ( V_9 ) ;
V_12 = 0 ;
while ( 1 ) {
unsigned long V_43 ;
bool V_53 , V_54 ;
F_20 ( & V_13 , V_43 ) ;
V_54 = V_31 -> V_39 ;
V_53 = V_31 -> V_40 ;
F_21 ( & V_13 , V_43 ) ;
if ( ! V_54 && ! V_53 ) {
V_45 = 0 ;
break;
}
if ( V_12 ++ == 3 ) {
F_26 ( L_3 ,
V_9 -> V_6 ) ;
V_45 = 0 ;
break;
}
V_45 = F_30 ( V_48 , V_47 ) ;
if ( V_45 == - V_55 )
break;
if ( V_45 ) {
F_26 ( L_4 , V_9 -> V_6 ) ;
break;
}
}
F_31 () ;
return V_45 ;
}
int F_32 ( struct V_2 * V_3 )
{
unsigned long V_47 = F_23 ( 500 ) ;
struct V_1 * V_14 ;
struct V_49 * V_50 ;
T_1 V_48 ;
int V_45 ;
int V_12 ;
if ( ! V_3 -> V_20 )
return 0 ;
V_50 = V_3 -> V_20 -> V_21 ;
if ( ! V_50 || V_50 -> V_51 != V_52 )
return 0 ;
if ( F_7 ( V_3 ) )
return 0 ;
V_45 = F_28 () ;
if ( V_45 )
return V_45 ;
V_48 = F_29 ( V_3 -> V_20 -> V_6 ) ;
V_14 = F_1 ( V_3 ) ;
V_12 = 0 ;
while ( 1 ) {
unsigned long V_43 ;
bool V_53 , V_54 ;
F_20 ( & V_13 , V_43 ) ;
V_54 = V_14 -> V_39 ;
V_53 = V_14 -> V_40 ;
F_21 ( & V_13 , V_43 ) ;
if ( ! V_54 && ! V_53 ) {
V_45 = 0 ;
break;
}
if ( V_12 ++ == 3 ) {
F_26 ( L_5 ,
V_3 -> V_6 ) ;
V_45 = 0 ;
break;
}
V_45 = F_30 ( V_48 , V_47 ) ;
if ( V_45 == - V_55 )
break;
if ( V_45 ) {
F_26 ( L_6 , V_3 -> V_6 ) ;
break;
}
}
F_31 () ;
return V_45 ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_25 * V_26 ;
bool V_56 , V_57 ;
struct V_7 * V_31 ;
int V_45 ;
F_34 ( L_7 , V_3 -> V_6 ) ;
if ( ! V_14 -> V_32 || ! V_14 -> V_39 )
return;
V_26 = & V_14 -> V_15 ;
V_31 = F_2 ( V_3 -> V_20 ) ;
V_57 = F_35 ( V_3 -> V_20 -> V_21 , V_26 -> V_58 ) ;
V_56 = V_3 -> V_20 -> V_21 -> type == V_59 ;
V_45 = F_36 ( V_3 -> V_6 , V_26 , V_56 , V_57 , & V_31 -> V_35 ) ;
if ( V_45 ) {
F_26 ( L_8 , V_3 -> V_6 ) ;
V_14 -> V_32 = false ;
F_37 ( V_3 -> V_6 , false ) ;
return;
}
V_14 -> V_39 = false ;
if ( V_31 -> V_37 )
V_14 -> V_40 = true ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_7 * V_31 ;
F_34 ( L_7 , V_3 -> V_6 ) ;
if ( ! V_14 -> V_41 )
return;
F_37 ( V_3 -> V_6 , V_14 -> V_32 ) ;
F_39 ( V_3 -> V_6 , V_14 -> V_60 ) ;
F_40 ( V_3 -> V_6 , V_14 -> V_61 , V_14 -> V_62 ) ;
V_31 = F_2 ( V_3 -> V_20 ) ;
V_14 -> V_41 = false ;
if ( V_31 -> V_37 )
V_14 -> V_42 = true ;
}
static void F_41 ( struct V_8 * V_9 )
{
struct V_7 * V_31 = F_2 ( V_9 ) ;
struct V_2 * V_3 ;
F_34 ( L_7 , V_9 -> V_6 ) ;
if ( ! V_31 -> V_32 )
return;
F_42 ( V_31 -> V_38 ) ;
F_10 (ovl, &mgr->overlays, list) {
F_33 ( V_3 ) ;
F_38 ( V_3 ) ;
}
if ( V_31 -> V_39 ) {
F_43 ( V_9 -> V_6 , & V_31 -> V_15 ) ;
V_31 -> V_39 = false ;
if ( V_31 -> V_37 )
V_31 -> V_40 = true ;
}
}
static void F_44 ( struct V_8 * V_9 )
{
struct V_7 * V_31 = F_2 ( V_9 ) ;
F_34 ( L_7 , V_9 -> V_6 ) ;
if ( ! V_31 -> V_41 )
return;
F_45 ( V_9 -> V_6 , & V_31 -> V_35 ) ;
V_31 -> V_41 = false ;
if ( V_31 -> V_37 )
V_31 -> V_42 = true ;
}
static void F_46 ( void )
{
const int V_36 = F_47 () ;
int V_12 ;
if ( ! V_4 . V_63 )
return;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 ) {
struct V_8 * V_9 ;
struct V_7 * V_31 ;
V_9 = F_16 ( V_12 ) ;
V_31 = F_2 ( V_9 ) ;
if ( V_31 -> V_32 ) {
if ( V_4 . V_63 ) {
F_48 ( V_4 . V_64 ) ;
V_4 . V_63 = false ;
}
if ( V_31 -> V_37 )
V_31 -> V_40 = true ;
}
}
}
static void F_49 ( void )
{
const int V_36 = F_47 () ;
int V_12 ;
F_46 () ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 ) {
struct V_8 * V_9 ;
struct V_7 * V_31 ;
int V_45 ;
V_9 = F_16 ( V_12 ) ;
V_31 = F_2 ( V_9 ) ;
if ( ! V_31 -> V_32 || F_8 ( V_9 ) || V_31 -> V_38 )
continue;
V_45 = F_12 ( V_9 ) ;
if ( V_45 ) {
F_26 ( L_9
L_10 , V_9 -> V_65 ) ;
continue;
}
F_41 ( V_9 ) ;
F_44 ( V_9 ) ;
}
}
static void F_50 ( void )
{
const int V_36 = F_47 () ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 ) {
struct V_8 * V_9 ;
struct V_7 * V_31 ;
V_9 = F_16 ( V_12 ) ;
V_31 = F_2 ( V_9 ) ;
if ( ! V_31 -> V_32 || F_8 ( V_9 ) || V_31 -> V_38 )
continue;
if ( ! F_17 ( V_9 ) )
continue;
V_31 -> V_38 = true ;
if ( ! V_4 . V_66 && F_14 () )
F_51 () ;
F_52 ( V_9 -> V_6 ) ;
}
}
static void F_53 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_7 * V_31 ;
struct V_1 * V_14 ;
V_31 = F_2 ( V_9 ) ;
V_31 -> V_40 = false ;
V_31 -> V_42 = false ;
F_10 (ovl, &mgr->overlays, list) {
V_14 = F_1 ( V_3 ) ;
V_14 -> V_40 = false ;
V_14 -> V_42 = false ;
}
}
void F_54 ( struct V_8 * V_9 )
{
struct V_7 * V_31 = F_2 ( V_9 ) ;
unsigned long V_43 ;
int V_45 ;
F_20 ( & V_13 , V_43 ) ;
F_42 ( V_31 -> V_37 ) ;
V_45 = F_12 ( V_9 ) ;
if ( V_45 ) {
F_26 ( L_11 ) ;
F_21 ( & V_13 , V_43 ) ;
return;
}
F_41 ( V_9 ) ;
F_44 ( V_9 ) ;
F_46 () ;
V_31 -> V_37 = true ;
if ( ! V_4 . V_66 && F_14 () )
F_51 () ;
F_55 ( V_9 -> V_6 , true ) ;
F_53 ( V_9 ) ;
F_21 ( & V_13 , V_43 ) ;
}
static void F_51 ( void )
{
const int V_36 = F_15 () ;
T_1 V_67 ;
int V_45 , V_12 ;
V_67 = 0 ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 )
V_67 |= F_29 ( V_12 ) ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 )
V_67 |= F_56 ( V_12 ) ;
V_45 = F_57 ( V_68 , NULL , V_67 ) ;
F_42 ( V_45 ) ;
V_4 . V_66 = true ;
}
static void F_58 ( void )
{
const int V_36 = F_15 () ;
T_1 V_67 ;
int V_45 , V_12 ;
V_67 = 0 ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 )
V_67 |= F_29 ( V_12 ) ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 )
V_67 |= F_56 ( V_12 ) ;
V_45 = F_59 ( V_68 , NULL , V_67 ) ;
F_42 ( V_45 ) ;
V_4 . V_66 = false ;
}
static void V_68 ( void * V_69 , T_1 V_67 )
{
const int V_36 = F_15 () ;
int V_12 ;
bool V_70 ;
F_60 ( & V_13 ) ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ ) {
struct V_8 * V_9 ;
struct V_7 * V_31 ;
bool V_71 ;
V_9 = F_16 ( V_12 ) ;
V_31 = F_2 ( V_9 ) ;
if ( ! V_31 -> V_32 )
continue;
V_71 = V_31 -> V_37 ;
V_31 -> V_37 = F_61 ( V_12 ) ;
if ( ! F_8 ( V_9 ) ) {
bool V_72 = V_31 -> V_38 ;
V_31 -> V_38 = F_62 ( V_12 ) ;
if ( V_72 && ! V_31 -> V_38 )
F_53 ( V_9 ) ;
}
}
F_49 () ;
F_50 () ;
V_70 = F_18 () ;
if ( ! V_70 )
F_63 ( & V_46 ) ;
if ( ! F_14 () )
F_58 () ;
F_64 ( & V_13 ) ;
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_14 ;
V_14 = F_1 ( V_3 ) ;
if ( ! V_14 -> V_33 )
return;
V_14 -> V_33 = false ;
V_14 -> V_39 = true ;
V_14 -> V_15 = V_14 -> V_19 ;
}
static void F_66 ( struct V_8 * V_9 )
{
struct V_7 * V_31 ;
V_31 = F_2 ( V_9 ) ;
if ( ! V_31 -> V_33 )
return;
V_31 -> V_33 = false ;
V_31 -> V_39 = true ;
V_31 -> V_15 = V_31 -> V_19 ;
}
int F_67 ( struct V_8 * V_9 )
{
unsigned long V_43 ;
struct V_2 * V_3 ;
int V_45 ;
F_68 ( L_12 , V_9 -> V_65 ) ;
F_20 ( & V_13 , V_43 ) ;
V_45 = F_13 ( V_9 ) ;
if ( V_45 ) {
F_21 ( & V_13 , V_43 ) ;
F_26 ( L_13 ) ;
return V_45 ;
}
F_10 (ovl, &mgr->overlays, list)
F_65 ( V_3 ) ;
F_66 ( V_9 ) ;
F_49 () ;
F_50 () ;
F_21 ( & V_13 , V_43 ) ;
return 0 ;
}
static void F_69 ( struct V_2 * V_3 , bool V_73 )
{
struct V_1 * V_14 ;
V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_32 == V_73 )
return;
V_14 -> V_32 = V_73 ;
V_14 -> V_41 = true ;
}
static void F_70 ( struct V_2 * V_3 ,
T_1 V_61 , T_1 V_62 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_61 == V_61 && V_14 -> V_62 == V_62 )
return;
V_14 -> V_61 = V_61 ;
V_14 -> V_62 = V_62 ;
V_14 -> V_41 = true ;
}
static void F_71 ( bool V_74 )
{
if ( V_4 . V_64 == V_74 )
return;
V_4 . V_64 = V_74 ;
V_4 . V_63 = true ;
}
static void F_72 ( struct V_2 * V_3 ,
bool V_74 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
T_1 V_61 , V_62 ;
if ( ! V_14 -> V_32 && ! V_14 -> V_34 )
return;
F_73 ( V_3 -> V_6 , & V_61 , & V_62 ,
V_74 , F_7 ( V_3 ) ) ;
F_70 ( V_3 , V_61 , V_62 ) ;
}
static void F_74 ( struct V_8 * V_9 ,
bool V_74 )
{
struct V_2 * V_3 ;
struct V_7 * V_31 ;
V_31 = F_2 ( V_9 ) ;
if ( ! V_31 -> V_32 )
return;
F_10 (ovl, &mgr->overlays, list)
F_72 ( V_3 , V_74 ) ;
}
static void F_75 ( bool V_74 )
{
const int V_36 = F_47 () ;
struct V_8 * V_9 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 ) {
V_9 = F_16 ( V_12 ) ;
F_74 ( V_9 , V_74 ) ;
}
}
static int F_76 ( void )
{
const int V_36 = F_47 () ;
struct V_8 * V_9 ;
struct V_7 * V_31 ;
int V_12 ;
int V_75 ;
V_75 = 0 ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 ) {
V_9 = F_16 ( V_12 ) ;
V_31 = F_2 ( V_9 ) ;
if ( ! V_31 -> V_32 )
continue;
V_75 ++ ;
}
return V_75 ;
}
static int F_77 ( void )
{
const int V_11 = F_78 () ;
struct V_2 * V_3 ;
struct V_1 * V_14 ;
struct V_7 * V_31 ;
int V_12 ;
int V_76 ;
V_76 = 0 ;
for ( V_12 = 0 ; V_12 < V_11 ; ++ V_12 ) {
V_3 = F_79 ( V_12 ) ;
V_14 = F_1 ( V_3 ) ;
if ( ! V_14 -> V_32 && ! V_14 -> V_34 )
continue;
V_31 = F_2 ( V_3 -> V_20 ) ;
if ( ! V_31 -> V_32 )
continue;
V_76 ++ ;
}
return V_76 ;
}
static bool F_80 ( void )
{
int V_75 = F_76 () ;
int V_76 = F_77 () ;
if ( ! F_6 ( V_77 ) )
return false ;
return V_75 <= 1 && V_76 <= 1 ;
}
int F_81 ( struct V_8 * V_9 )
{
struct V_7 * V_31 = F_2 ( V_9 ) ;
unsigned long V_43 ;
int V_45 ;
bool V_64 ;
F_82 ( & V_78 ) ;
if ( V_31 -> V_32 )
goto V_79;
F_20 ( & V_13 , V_43 ) ;
V_31 -> V_32 = true ;
V_45 = F_12 ( V_9 ) ;
if ( V_45 ) {
F_26 ( L_14 ,
V_9 -> V_6 ) ;
goto V_80;
}
V_64 = F_80 () ;
F_75 ( V_64 ) ;
F_71 ( V_64 ) ;
F_49 () ;
F_50 () ;
F_21 ( & V_13 , V_43 ) ;
F_19 () ;
F_20 ( & V_13 , V_43 ) ;
if ( ! F_8 ( V_9 ) )
V_31 -> V_37 = true ;
F_21 ( & V_13 , V_43 ) ;
if ( ! F_8 ( V_9 ) )
F_55 ( V_9 -> V_6 , true ) ;
V_79:
F_83 ( & V_78 ) ;
return 0 ;
V_80:
V_31 -> V_32 = false ;
F_21 ( & V_13 , V_43 ) ;
F_83 ( & V_78 ) ;
return V_45 ;
}
void F_84 ( struct V_8 * V_9 )
{
struct V_7 * V_31 = F_2 ( V_9 ) ;
unsigned long V_43 ;
bool V_64 ;
F_82 ( & V_78 ) ;
if ( ! V_31 -> V_32 )
goto V_79;
if ( ! F_8 ( V_9 ) )
F_55 ( V_9 -> V_6 , false ) ;
F_20 ( & V_13 , V_43 ) ;
V_31 -> V_37 = false ;
V_31 -> V_32 = false ;
V_64 = F_80 () ;
F_75 ( V_64 ) ;
F_71 ( V_64 ) ;
F_49 () ;
F_50 () ;
F_21 ( & V_13 , V_43 ) ;
F_19 () ;
V_79:
F_83 ( & V_78 ) ;
}
int F_85 ( struct V_8 * V_9 ,
struct V_27 * V_15 )
{
struct V_7 * V_31 = F_2 ( V_9 ) ;
unsigned long V_43 ;
int V_45 ;
V_45 = F_86 ( V_9 , V_15 ) ;
if ( V_45 )
return V_45 ;
F_20 ( & V_13 , V_43 ) ;
V_31 -> V_19 = * V_15 ;
V_31 -> V_33 = true ;
F_21 ( & V_13 , V_43 ) ;
return 0 ;
}
void F_87 ( struct V_8 * V_9 ,
struct V_27 * V_15 )
{
struct V_7 * V_31 = F_2 ( V_9 ) ;
unsigned long V_43 ;
F_20 ( & V_13 , V_43 ) ;
* V_15 = V_31 -> V_19 ;
F_21 ( & V_13 , V_43 ) ;
}
int F_88 ( struct V_8 * V_9 ,
struct V_49 * V_50 )
{
int V_45 ;
F_82 ( & V_78 ) ;
if ( V_50 -> V_20 ) {
F_26 ( L_15 ,
V_50 -> V_65 , V_50 -> V_20 -> V_65 ) ;
V_45 = - V_81 ;
goto V_80;
}
if ( ( V_9 -> V_82 & V_50 -> type ) == 0 ) {
F_26 ( L_16 ,
V_50 -> V_65 , V_9 -> V_65 ) ;
V_45 = - V_81 ;
goto V_80;
}
V_50 -> V_20 = V_9 ;
V_9 -> V_21 = V_50 ;
F_83 ( & V_78 ) ;
return 0 ;
V_80:
F_83 ( & V_78 ) ;
return V_45 ;
}
int F_89 ( struct V_8 * V_9 )
{
int V_45 ;
F_82 ( & V_78 ) ;
if ( ! V_9 -> V_21 ) {
F_26 ( L_17 ) ;
V_45 = - V_81 ;
goto V_80;
}
if ( V_9 -> V_21 -> V_51 != V_83 ) {
V_45 = - V_81 ;
goto V_80;
}
V_9 -> V_21 -> V_20 = NULL ;
V_9 -> V_21 = NULL ;
F_83 ( & V_78 ) ;
return 0 ;
V_80:
F_83 ( & V_78 ) ;
return V_45 ;
}
static void F_90 ( struct V_8 * V_9 ,
struct V_84 * V_35 )
{
struct V_7 * V_31 = F_2 ( V_9 ) ;
V_31 -> V_35 = * V_35 ;
V_31 -> V_41 = true ;
}
void F_91 ( struct V_8 * V_9 ,
struct V_84 * V_35 )
{
unsigned long V_43 ;
F_82 ( & V_78 ) ;
F_20 ( & V_13 , V_43 ) ;
F_90 ( V_9 , V_35 ) ;
F_49 () ;
F_50 () ;
F_21 ( & V_13 , V_43 ) ;
F_19 () ;
F_83 ( & V_78 ) ;
}
int F_92 ( struct V_2 * V_3 ,
struct V_25 * V_15 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_43 ;
int V_45 ;
V_45 = F_93 ( V_3 , V_15 ) ;
if ( V_45 )
return V_45 ;
F_20 ( & V_13 , V_43 ) ;
V_14 -> V_19 = * V_15 ;
V_14 -> V_33 = true ;
F_21 ( & V_13 , V_43 ) ;
return 0 ;
}
void F_94 ( struct V_2 * V_3 ,
struct V_25 * V_15 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_43 ;
F_20 ( & V_13 , V_43 ) ;
* V_15 = V_14 -> V_19 ;
F_21 ( & V_13 , V_43 ) ;
}
int F_95 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_43 ;
int V_45 ;
if ( ! V_9 )
return - V_81 ;
F_82 ( & V_78 ) ;
if ( V_3 -> V_20 ) {
F_26 ( L_18 ,
V_3 -> V_65 , V_3 -> V_20 -> V_65 ) ;
V_45 = - V_81 ;
goto V_80;
}
F_20 ( & V_13 , V_43 ) ;
if ( V_14 -> V_32 ) {
F_21 ( & V_13 , V_43 ) ;
F_26 ( L_19 ) ;
V_45 = - V_81 ;
goto V_80;
}
V_14 -> V_60 = V_9 -> V_6 ;
V_14 -> V_41 = true ;
V_3 -> V_20 = V_9 ;
F_96 ( & V_3 -> V_85 , & V_9 -> V_86 ) ;
F_21 ( & V_13 , V_43 ) ;
F_83 ( & V_78 ) ;
return 0 ;
V_80:
F_83 ( & V_78 ) ;
return V_45 ;
}
int F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_43 ;
int V_45 ;
F_82 ( & V_78 ) ;
if ( ! V_3 -> V_20 ) {
F_26 ( L_20 ) ;
V_45 = - V_81 ;
goto V_80;
}
F_20 ( & V_13 , V_43 ) ;
if ( V_14 -> V_32 ) {
F_21 ( & V_13 , V_43 ) ;
F_26 ( L_21 ) ;
V_45 = - V_81 ;
goto V_80;
}
V_14 -> V_60 = - 1 ;
V_3 -> V_20 = NULL ;
F_98 ( & V_3 -> V_85 ) ;
F_21 ( & V_13 , V_43 ) ;
F_83 ( & V_78 ) ;
return 0 ;
V_80:
F_83 ( & V_78 ) ;
return V_45 ;
}
bool F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_43 ;
bool V_87 ;
F_20 ( & V_13 , V_43 ) ;
V_87 = V_14 -> V_32 ;
F_21 ( & V_13 , V_43 ) ;
return V_87 ;
}
int F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_43 ;
bool V_64 ;
int V_45 ;
F_82 ( & V_78 ) ;
if ( V_14 -> V_32 ) {
V_45 = 0 ;
goto V_88;
}
if ( V_3 -> V_20 == NULL || V_3 -> V_20 -> V_21 == NULL ) {
V_45 = - V_81 ;
goto V_88;
}
F_20 ( & V_13 , V_43 ) ;
V_14 -> V_34 = true ;
V_45 = F_12 ( V_3 -> V_20 ) ;
if ( V_45 ) {
F_26 ( L_22 ,
V_3 -> V_6 ) ;
goto V_89;
}
V_64 = F_80 () ;
F_75 ( V_64 ) ;
F_71 ( V_64 ) ;
F_49 () ;
F_50 () ;
F_21 ( & V_13 , V_43 ) ;
F_19 () ;
F_20 ( & V_13 , V_43 ) ;
V_14 -> V_34 = false ;
F_69 ( V_3 , true ) ;
F_49 () ;
F_50 () ;
F_21 ( & V_13 , V_43 ) ;
F_19 () ;
F_83 ( & V_78 ) ;
return 0 ;
V_89:
V_14 -> V_34 = false ;
F_21 ( & V_13 , V_43 ) ;
V_88:
F_83 ( & V_78 ) ;
return V_45 ;
}
int F_101 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_43 ;
bool V_64 ;
int V_45 ;
F_82 ( & V_78 ) ;
if ( ! V_14 -> V_32 ) {
V_45 = 0 ;
goto V_80;
}
if ( V_3 -> V_20 == NULL || V_3 -> V_20 -> V_21 == NULL ) {
V_45 = - V_81 ;
goto V_80;
}
F_20 ( & V_13 , V_43 ) ;
F_69 ( V_3 , false ) ;
F_49 () ;
F_50 () ;
F_21 ( & V_13 , V_43 ) ;
F_19 () ;
F_20 ( & V_13 , V_43 ) ;
V_64 = F_80 () ;
F_75 ( V_64 ) ;
F_71 ( V_64 ) ;
F_49 () ;
F_50 () ;
F_21 ( & V_13 , V_43 ) ;
F_19 () ;
F_83 ( & V_78 ) ;
return 0 ;
V_80:
F_83 ( & V_78 ) ;
return V_45 ;
}
