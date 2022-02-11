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
static inline struct V_51 * F_26 ( struct V_2 * V_3 )
{
return V_3 -> V_27 ?
( V_3 -> V_27 -> V_52 ? V_3 -> V_27 -> V_52 -> V_53 : NULL ) :
NULL ;
}
static inline struct V_51 * F_27 ( struct V_8 * V_9 )
{
return V_9 -> V_52 ? V_9 -> V_52 -> V_53 : NULL ;
}
static int F_28 ( struct V_8 * V_9 )
{
unsigned long V_54 = F_23 ( 500 ) ;
struct V_51 * V_55 = V_9 -> V_56 ( V_9 ) ;
T_1 V_57 ;
int V_49 ;
V_49 = F_29 () ;
if ( V_49 )
return V_49 ;
if ( V_55 -> type == V_58 )
V_57 = V_59 ;
else if ( V_55 -> type == V_60 )
V_57 = V_61 ;
else
V_57 = F_30 ( V_9 -> V_6 ) ;
V_49 = F_31 ( V_57 , V_54 ) ;
F_32 () ;
return V_49 ;
}
static int F_33 ( struct V_8 * V_9 )
{
unsigned long V_54 = F_23 ( 500 ) ;
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
bool V_62 , V_63 ;
F_20 ( & V_14 , V_47 ) ;
V_63 = V_12 -> V_43 ;
V_62 = V_12 -> V_44 ;
F_21 ( & V_14 , V_47 ) ;
if ( ! V_63 && ! V_62 ) {
V_49 = 0 ;
break;
}
if ( V_13 ++ == 3 ) {
F_34 ( L_2 ,
V_9 -> V_6 ) ;
V_49 = 0 ;
break;
}
V_49 = F_31 ( V_57 , V_54 ) ;
if ( V_49 == - V_64 )
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
unsigned long V_54 = F_23 ( 500 ) ;
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
bool V_62 , V_63 ;
F_20 ( & V_14 , V_47 ) ;
V_63 = V_15 -> V_43 ;
V_62 = V_15 -> V_44 ;
F_21 ( & V_14 , V_47 ) ;
if ( ! V_63 && ! V_62 ) {
V_49 = 0 ;
break;
}
if ( V_13 ++ == 3 ) {
F_34 ( L_4 ,
V_3 -> V_6 ) ;
V_49 = 0 ;
break;
}
V_49 = F_31 ( V_57 , V_54 ) ;
if ( V_49 == - V_64 )
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
bool V_65 ;
struct V_7 * V_12 ;
int V_49 ;
F_37 ( L_6 , V_3 -> V_6 ) ;
if ( ! V_15 -> V_36 || ! V_15 -> V_43 )
return;
V_31 = & V_15 -> V_16 ;
V_12 = F_2 ( V_3 -> V_27 ) ;
V_65 = F_38 ( V_12 -> V_22 , V_31 -> V_66 ) ;
V_49 = F_39 ( V_3 -> V_6 , V_31 , V_65 , & V_12 -> V_39 , false ) ;
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
F_42 ( V_3 -> V_6 , V_15 -> V_67 , V_15 -> V_68 ) ;
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
L_12 , V_9 -> V_69 ) ;
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
if ( ! V_4 . V_70 && F_14 () )
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
static void F_56 ( struct V_8 * V_9 )
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
if ( ! V_4 . V_70 && F_14 () )
F_53 () ;
F_57 ( V_9 -> V_6 ) ;
F_21 ( & V_14 , V_47 ) ;
}
static void F_53 ( void )
{
const int V_40 = F_15 () ;
T_1 V_71 ;
int V_49 , V_13 ;
V_71 = 0 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 )
V_71 |= F_30 ( V_13 ) ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 )
V_71 |= F_58 ( V_13 ) ;
V_49 = F_59 ( V_72 , NULL , V_71 ) ;
F_44 ( V_49 ) ;
V_4 . V_70 = true ;
}
static void F_60 ( void )
{
const int V_40 = F_15 () ;
T_1 V_71 ;
int V_49 , V_13 ;
V_71 = 0 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 )
V_71 |= F_30 ( V_13 ) ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 )
V_71 |= F_58 ( V_13 ) ;
V_49 = F_61 ( V_72 , NULL , V_71 ) ;
F_44 ( V_49 ) ;
V_4 . V_70 = false ;
}
static void V_72 ( void * V_73 , T_1 V_71 )
{
const int V_40 = F_15 () ;
int V_13 ;
bool V_74 ;
F_62 ( & V_14 ) ;
for ( V_13 = 0 ; V_13 < V_40 ; V_13 ++ ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_36 )
continue;
V_12 -> V_41 = F_63 ( V_13 ) ;
if ( ! F_8 ( V_9 ) ) {
bool V_75 = V_12 -> V_42 ;
V_12 -> V_42 = F_64 ( V_13 ) ;
if ( V_75 && ! V_12 -> V_42 )
F_55 ( V_9 ) ;
}
}
F_50 () ;
F_52 () ;
V_74 = F_18 () ;
if ( ! V_74 )
F_65 ( & V_50 ) ;
for ( V_13 = 0 ; V_13 < V_40 ; V_13 ++ ) {
struct V_8 * V_9 ;
struct V_7 * V_12 ;
V_9 = F_16 ( V_13 ) ;
V_12 = F_2 ( V_9 ) ;
if ( ! F_8 ( V_9 ) || ! V_12 -> V_76 )
continue;
if ( V_71 & F_58 ( V_13 ) )
V_12 -> V_76 ( V_12 -> V_77 ) ;
}
if ( ! F_14 () )
F_60 () ;
F_66 ( & V_14 ) ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_15 ;
V_15 = F_1 ( V_3 ) ;
if ( ! V_15 -> V_37 )
return;
V_15 -> V_37 = false ;
V_15 -> V_43 = true ;
V_15 -> V_16 = V_15 -> V_20 ;
}
static void F_68 ( struct V_8 * V_9 )
{
struct V_7 * V_12 ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_37 )
return;
V_12 -> V_37 = false ;
V_12 -> V_43 = true ;
V_12 -> V_16 = V_12 -> V_20 ;
}
static int F_69 ( struct V_8 * V_9 )
{
unsigned long V_47 ;
struct V_2 * V_3 ;
int V_49 ;
F_37 ( L_14 , V_9 -> V_69 ) ;
F_20 ( & V_14 , V_47 ) ;
V_49 = F_13 ( V_9 ) ;
if ( V_49 ) {
F_21 ( & V_14 , V_47 ) ;
F_34 ( L_15 ) ;
return V_49 ;
}
F_10 (ovl, &mgr->overlays, list)
F_67 ( V_3 ) ;
F_68 ( V_9 ) ;
F_50 () ;
F_52 () ;
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
static void F_70 ( struct V_2 * V_3 , bool V_78 )
{
struct V_1 * V_15 ;
V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_36 == V_78 )
return;
V_15 -> V_36 = V_78 ;
V_15 -> V_45 = true ;
}
static void F_71 ( struct V_2 * V_3 ,
T_1 V_67 , T_1 V_68 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
if ( V_15 -> V_67 == V_67 && V_15 -> V_68 == V_68 )
return;
V_15 -> V_67 = V_67 ;
V_15 -> V_68 = V_68 ;
V_15 -> V_45 = true ;
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
T_1 V_67 , V_68 ;
bool V_79 = false ;
if ( ! V_15 -> V_36 && ! V_15 -> V_38 )
return;
F_73 ( V_3 -> V_6 , & V_67 , & V_68 ,
V_79 , F_7 ( V_3 ) ) ;
F_71 ( V_3 , V_67 , V_68 ) ;
}
static void F_74 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_7 * V_12 ;
V_12 = F_2 ( V_9 ) ;
if ( ! V_12 -> V_36 )
return;
F_10 (ovl, &mgr->overlays, list)
F_72 ( V_3 ) ;
}
static void F_75 ( void )
{
const int V_40 = F_51 () ;
struct V_8 * V_9 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_40 ; ++ V_13 ) {
V_9 = F_16 ( V_13 ) ;
F_74 ( V_9 ) ;
}
}
static int F_76 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
int V_49 ;
F_77 ( & V_80 ) ;
if ( V_12 -> V_36 )
goto V_81;
F_20 ( & V_14 , V_47 ) ;
V_12 -> V_36 = true ;
V_49 = F_12 ( V_9 ) ;
if ( V_49 ) {
F_34 ( L_16 ,
V_9 -> V_6 ) ;
goto V_82;
}
F_75 () ;
F_50 () ;
F_52 () ;
if ( ! F_8 ( V_9 ) )
V_12 -> V_41 = true ;
if ( ! V_4 . V_70 && F_14 () )
F_53 () ;
F_21 ( & V_14 , V_47 ) ;
if ( ! F_8 ( V_9 ) )
F_57 ( V_9 -> V_6 ) ;
V_81:
F_78 ( & V_80 ) ;
return 0 ;
V_82:
V_12 -> V_36 = false ;
F_21 ( & V_14 , V_47 ) ;
F_78 ( & V_80 ) ;
return V_49 ;
}
static void F_79 ( struct V_8 * V_9 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
F_77 ( & V_80 ) ;
if ( ! V_12 -> V_36 )
goto V_81;
if ( ! F_8 ( V_9 ) )
F_80 ( V_9 -> V_6 ) ;
F_20 ( & V_14 , V_47 ) ;
V_12 -> V_41 = false ;
V_12 -> V_36 = false ;
F_21 ( & V_14 , V_47 ) ;
V_81:
F_78 ( & V_80 ) ;
}
static int F_81 ( struct V_8 * V_9 ,
struct V_32 * V_16 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
int V_49 ;
V_49 = F_82 ( V_9 , V_16 ) ;
if ( V_49 )
return V_49 ;
F_20 ( & V_14 , V_47 ) ;
V_12 -> V_20 = * V_16 ;
V_12 -> V_37 = true ;
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
static void F_83 ( struct V_8 * V_9 ,
struct V_32 * V_16 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
F_20 ( & V_14 , V_47 ) ;
* V_16 = V_12 -> V_20 ;
F_21 ( & V_14 , V_47 ) ;
}
static int F_84 ( struct V_8 * V_9 ,
struct V_83 * V_52 )
{
int V_49 ;
F_77 ( & V_80 ) ;
if ( V_9 -> V_52 ) {
F_34 ( L_17 ,
V_9 -> V_69 ) ;
V_49 = - V_84 ;
goto V_82;
}
if ( ( V_9 -> V_85 & V_52 -> V_6 ) == 0 ) {
F_34 ( L_18 ,
V_9 -> V_69 ) ;
V_49 = - V_84 ;
goto V_82;
}
V_52 -> V_27 = V_9 ;
V_9 -> V_52 = V_52 ;
F_78 ( & V_80 ) ;
return 0 ;
V_82:
F_78 ( & V_80 ) ;
return V_49 ;
}
static int F_85 ( struct V_8 * V_9 )
{
int V_49 ;
struct V_7 * V_12 = F_2 ( V_9 ) ;
unsigned long V_47 ;
F_77 ( & V_80 ) ;
if ( ! V_9 -> V_52 ) {
F_34 ( L_19 ) ;
V_49 = - V_84 ;
goto V_82;
}
F_20 ( & V_14 , V_47 ) ;
if ( V_12 -> V_36 ) {
F_34 ( L_20 ) ;
V_49 = - V_84 ;
goto V_86;
}
F_21 ( & V_14 , V_47 ) ;
V_9 -> V_52 -> V_27 = NULL ;
V_9 -> V_52 = NULL ;
F_78 ( & V_80 ) ;
return 0 ;
V_86:
F_21 ( & V_14 , V_47 ) ;
V_82:
F_78 ( & V_80 ) ;
return V_49 ;
}
static void F_86 ( struct V_8 * V_9 ,
const struct V_87 * V_39 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
V_12 -> V_39 = * V_39 ;
V_12 -> V_45 = true ;
}
static void F_87 ( struct V_8 * V_9 ,
const struct V_87 * V_39 )
{
unsigned long V_47 ;
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_20 ( & V_14 , V_47 ) ;
if ( V_12 -> V_41 ) {
F_34 ( L_21 ,
V_9 -> V_69 ) ;
goto V_81;
}
F_86 ( V_9 , V_39 ) ;
V_81:
F_21 ( & V_14 , V_47 ) ;
}
static void F_88 ( struct V_8 * V_9 ,
const struct V_88 * V_89 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
V_12 -> V_22 = * V_89 ;
V_12 -> V_45 = true ;
}
static void F_89 ( struct V_8 * V_9 ,
const struct V_88 * V_89 )
{
unsigned long V_47 ;
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_20 ( & V_14 , V_47 ) ;
if ( V_12 -> V_36 ) {
F_34 ( L_22 ,
V_9 -> V_69 ) ;
goto V_81;
}
F_88 ( V_9 , V_89 ) ;
V_81:
F_21 ( & V_14 , V_47 ) ;
}
static int F_90 ( struct V_2 * V_3 ,
struct V_30 * V_16 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
V_49 = F_91 ( V_3 , V_16 ) ;
if ( V_49 )
return V_49 ;
F_20 ( & V_14 , V_47 ) ;
V_15 -> V_20 = * V_16 ;
V_15 -> V_37 = true ;
F_21 ( & V_14 , V_47 ) ;
return 0 ;
}
static void F_92 ( struct V_2 * V_3 ,
struct V_30 * V_16 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
F_20 ( & V_14 , V_47 ) ;
* V_16 = V_15 -> V_20 ;
F_21 ( & V_14 , V_47 ) ;
}
static int F_93 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
if ( ! V_9 )
return - V_84 ;
F_77 ( & V_80 ) ;
if ( V_3 -> V_27 ) {
F_34 ( L_23 ,
V_3 -> V_69 , V_3 -> V_27 -> V_69 ) ;
V_49 = - V_84 ;
goto V_82;
}
V_49 = F_29 () ;
if ( V_49 )
goto V_82;
F_20 ( & V_14 , V_47 ) ;
if ( V_15 -> V_36 ) {
F_21 ( & V_14 , V_47 ) ;
F_34 ( L_24 ) ;
V_49 = - V_84 ;
goto V_86;
}
F_94 ( V_3 -> V_6 , V_9 -> V_6 ) ;
V_3 -> V_27 = V_9 ;
F_95 ( & V_3 -> V_90 , & V_9 -> V_91 ) ;
F_21 ( & V_14 , V_47 ) ;
F_32 () ;
F_78 ( & V_80 ) ;
return 0 ;
V_86:
F_32 () ;
V_82:
F_78 ( & V_80 ) ;
return V_49 ;
}
static int F_96 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
F_77 ( & V_80 ) ;
if ( ! V_3 -> V_27 ) {
F_34 ( L_25 ) ;
V_49 = - V_84 ;
goto V_82;
}
F_20 ( & V_14 , V_47 ) ;
if ( V_15 -> V_36 ) {
F_21 ( & V_14 , V_47 ) ;
F_34 ( L_26 ) ;
V_49 = - V_84 ;
goto V_82;
}
F_21 ( & V_14 , V_47 ) ;
F_19 () ;
F_20 ( & V_14 , V_47 ) ;
if ( F_7 ( V_3 ) && V_15 -> V_45 ) {
F_21 ( & V_14 , V_47 ) ;
F_34 ( L_27 ) ;
V_49 = - V_84 ;
goto V_82;
}
V_3 -> V_27 = NULL ;
F_97 ( & V_3 -> V_90 ) ;
F_21 ( & V_14 , V_47 ) ;
F_78 ( & V_80 ) ;
return 0 ;
V_82:
F_78 ( & V_80 ) ;
return V_49 ;
}
static bool F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
bool V_92 ;
F_20 ( & V_14 , V_47 ) ;
V_92 = V_15 -> V_36 ;
F_21 ( & V_14 , V_47 ) ;
return V_92 ;
}
static int F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
F_77 ( & V_80 ) ;
if ( V_15 -> V_36 ) {
V_49 = 0 ;
goto V_86;
}
if ( V_3 -> V_27 == NULL || V_3 -> V_27 -> V_52 == NULL ) {
V_49 = - V_84 ;
goto V_86;
}
F_20 ( & V_14 , V_47 ) ;
V_15 -> V_38 = true ;
V_49 = F_12 ( V_3 -> V_27 ) ;
if ( V_49 ) {
F_34 ( L_28 ,
V_3 -> V_6 ) ;
goto V_93;
}
F_75 () ;
V_15 -> V_38 = false ;
F_70 ( V_3 , true ) ;
F_50 () ;
F_52 () ;
F_21 ( & V_14 , V_47 ) ;
F_78 ( & V_80 ) ;
return 0 ;
V_93:
V_15 -> V_38 = false ;
F_21 ( & V_14 , V_47 ) ;
V_86:
F_78 ( & V_80 ) ;
return V_49 ;
}
static int F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned long V_47 ;
int V_49 ;
F_77 ( & V_80 ) ;
if ( ! V_15 -> V_36 ) {
V_49 = 0 ;
goto V_82;
}
if ( V_3 -> V_27 == NULL || V_3 -> V_27 -> V_52 == NULL ) {
V_49 = - V_84 ;
goto V_82;
}
F_20 ( & V_14 , V_47 ) ;
F_70 ( V_3 , false ) ;
F_50 () ;
F_52 () ;
F_21 ( & V_14 , V_47 ) ;
F_78 ( & V_80 ) ;
return 0 ;
V_82:
F_78 ( & V_80 ) ;
return V_49 ;
}
static int F_101 ( struct V_8 * V_9 ,
void (* F_102)( void * ) , void * V_73 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
if ( V_12 -> V_76 )
return - V_94 ;
V_12 -> V_76 = F_102 ;
V_12 -> V_77 = V_73 ;
return 0 ;
}
static void F_103 ( struct V_8 * V_9 ,
void (* F_102)( void * ) , void * V_73 )
{
struct V_7 * V_12 = F_2 ( V_9 ) ;
F_44 ( V_12 -> V_76 != F_102 ||
V_12 -> V_77 != V_73 ) ;
V_12 -> V_76 = NULL ;
V_12 -> V_77 = NULL ;
}
int F_104 ( void )
{
struct V_95 * V_96 = F_105 () ;
struct V_51 * V_55 = NULL ;
int V_13 , V_49 ;
F_77 ( & V_97 ) ;
if ( V_98 ++ > 0 )
goto V_81;
F_3 () ;
F_106 ( V_96 ) ;
F_107 ( V_96 ) ;
for ( V_13 = 0 ; V_13 < F_51 () ; V_13 ++ ) {
struct V_8 * V_9 ;
V_9 = F_16 ( V_13 ) ;
V_9 -> V_99 = & F_84 ;
V_9 -> V_100 = & F_85 ;
V_9 -> V_101 = & F_69 ;
V_9 -> V_102 = & F_81 ;
V_9 -> V_103 = & F_83 ;
V_9 -> V_104 = & F_33 ;
V_9 -> V_105 = & F_28 ;
V_9 -> V_56 = & F_27 ;
}
for ( V_13 = 0 ; V_13 < F_108 () ; V_13 ++ ) {
struct V_2 * V_3 = F_109 ( V_13 ) ;
V_3 -> V_106 = & F_98 ;
V_3 -> V_78 = & F_99 ;
V_3 -> V_107 = & F_100 ;
V_3 -> V_108 = & F_93 ;
V_3 -> V_109 = & F_96 ;
V_3 -> V_110 = & F_90 ;
V_3 -> V_111 = & F_92 ;
V_3 -> V_104 = & F_35 ;
V_3 -> V_56 = & F_26 ;
}
V_49 = F_110 ( & V_112 ) ;
if ( V_49 )
goto V_113;
F_111 (dssdev) {
V_49 = F_112 ( V_96 , V_55 ) ;
if ( V_49 )
goto V_114;
}
F_29 () ;
V_49 = F_113 () ;
if ( V_49 )
goto V_115;
F_32 () ;
V_81:
F_78 ( & V_97 ) ;
return 0 ;
V_115:
F_32 () ;
V_114:
F_114 () ;
V_113:
F_115 ( V_96 ) ;
F_116 ( V_96 ) ;
V_98 -- ;
F_78 ( & V_97 ) ;
return V_49 ;
}
void F_117 ( void )
{
struct V_95 * V_96 = F_105 () ;
struct V_51 * V_55 = NULL ;
F_77 ( & V_97 ) ;
if ( -- V_98 > 0 )
goto V_81;
F_118 () ;
F_111 (dssdev)
F_119 ( V_96 , V_55 ) ;
F_114 () ;
F_115 ( V_96 ) ;
F_116 ( V_96 ) ;
V_81:
F_78 ( & V_97 ) ;
}
