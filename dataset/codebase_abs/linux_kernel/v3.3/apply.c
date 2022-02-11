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
struct V_24 * V_25 , bool V_26 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_2 * V_3 ;
struct V_27 * V_31 [ V_32 ] ;
struct V_1 * V_14 ;
struct V_7 * V_33 ;
V_33 = F_2 ( V_9 ) ;
if ( V_26 && V_33 -> V_34 )
V_30 = & V_33 -> V_19 ;
else
V_30 = & V_33 -> V_15 ;
F_10 (ovl, &mgr->overlays, list) {
V_14 = F_1 ( V_3 ) ;
if ( ! V_14 -> V_35 && ! V_14 -> V_36 )
V_28 = NULL ;
else if ( V_26 && V_14 -> V_34 )
V_28 = & V_14 -> V_19 ;
else
V_28 = & V_14 -> V_15 ;
V_31 [ V_3 -> V_6 ] = V_28 ;
}
return F_11 ( V_9 , V_25 , V_30 , V_31 ) ;
}
static int F_12 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
return F_9 ( V_9 , V_25 , false ) ;
}
static int F_13 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
return F_9 ( V_9 , V_25 , true ) ;
}
static bool F_14 ( void )
{
const int V_37 = F_15 () ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_37 ; ++ V_12 ) {
struct V_8 * V_9 ;
struct V_7 * V_33 ;
struct V_2 * V_3 ;
V_9 = F_16 ( V_12 ) ;
V_33 = F_2 ( V_9 ) ;
if ( ! V_33 -> V_35 )
continue;
if ( F_8 ( V_9 ) ) {
if ( V_33 -> V_38 )
return true ;
} else {
if ( V_33 -> V_39 )
return true ;
if ( V_33 -> V_40 )
return true ;
if ( V_33 -> V_41 )
return true ;
F_10 (ovl, &mgr->overlays, list) {
struct V_1 * V_14 ;
V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_42 )
return true ;
if ( V_14 -> V_43 )
return true ;
if ( ! V_14 -> V_35 )
continue;
if ( V_14 -> V_40 )
return true ;
if ( V_14 -> V_41 )
return true ;
}
}
}
return false ;
}
static bool F_17 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_7 * V_33 ;
struct V_1 * V_14 ;
V_33 = F_2 ( V_9 ) ;
if ( V_33 -> V_41 )
return true ;
F_10 (ovl, &mgr->overlays, list) {
V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_41 || V_14 -> V_43 )
return true ;
}
return false ;
}
static bool F_18 ( void )
{
const int V_11 = F_19 () ;
struct V_1 * V_14 ;
struct V_2 * V_3 ;
struct V_7 * V_33 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_11 ; ++ V_12 ) {
V_3 = F_20 ( V_12 ) ;
V_14 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_20 )
continue;
V_33 = F_2 ( V_3 -> V_20 ) ;
if ( ! V_33 -> V_35 )
continue;
if ( ! V_33 -> V_38 )
continue;
if ( V_14 -> V_42 || V_14 -> V_43 )
return true ;
}
return false ;
}
static void F_21 ( void )
{
bool V_38 ;
unsigned long V_44 ;
unsigned long V_45 ;
F_22 ( & V_13 , V_44 ) ;
V_38 = F_18 () ;
if ( ! V_38 ) {
F_23 ( & V_13 , V_44 ) ;
return;
}
F_24 ( & V_46 ) ;
F_23 ( & V_13 , V_44 ) ;
V_45 = F_25 ( 500 ) ;
F_26 ( & V_46 , V_45 ) ;
V_38 = F_18 () ;
F_27 ( V_38 ) ;
}
int F_28 ( struct V_8 * V_9 )
{
unsigned long V_47 = F_25 ( 500 ) ;
struct V_7 * V_33 ;
T_1 V_48 ;
int V_49 ;
int V_12 ;
struct V_24 * V_25 = V_9 -> V_21 ;
if ( ! V_25 || V_25 -> V_50 != V_51 )
return 0 ;
if ( F_8 ( V_9 ) )
return 0 ;
V_48 = F_29 ( V_9 -> V_6 ) ;
V_33 = F_2 ( V_9 ) ;
V_12 = 0 ;
while ( 1 ) {
unsigned long V_44 ;
bool V_52 , V_53 ;
F_22 ( & V_13 , V_44 ) ;
V_53 = V_33 -> V_40 ;
V_52 = V_33 -> V_41 ;
F_23 ( & V_13 , V_44 ) ;
if ( ! V_53 && ! V_52 ) {
V_49 = 0 ;
break;
}
if ( V_12 ++ == 3 ) {
F_30 ( L_1 ,
V_9 -> V_6 ) ;
V_49 = 0 ;
break;
}
V_49 = F_31 ( V_48 , V_47 ) ;
if ( V_49 == - V_54 )
break;
if ( V_49 ) {
F_30 ( L_2 , V_9 -> V_6 ) ;
break;
}
}
return V_49 ;
}
int F_32 ( struct V_2 * V_3 )
{
unsigned long V_47 = F_25 ( 500 ) ;
struct V_1 * V_14 ;
struct V_24 * V_25 ;
T_1 V_48 ;
int V_49 ;
int V_12 ;
if ( ! V_3 -> V_20 )
return 0 ;
V_25 = V_3 -> V_20 -> V_21 ;
if ( ! V_25 || V_25 -> V_50 != V_51 )
return 0 ;
if ( F_7 ( V_3 ) )
return 0 ;
V_48 = F_29 ( V_3 -> V_20 -> V_6 ) ;
V_14 = F_1 ( V_3 ) ;
V_12 = 0 ;
while ( 1 ) {
unsigned long V_44 ;
bool V_52 , V_53 ;
F_22 ( & V_13 , V_44 ) ;
V_53 = V_14 -> V_40 ;
V_52 = V_14 -> V_41 ;
F_23 ( & V_13 , V_44 ) ;
if ( ! V_53 && ! V_52 ) {
V_49 = 0 ;
break;
}
if ( V_12 ++ == 3 ) {
F_30 ( L_3 ,
V_3 -> V_6 ) ;
V_49 = 0 ;
break;
}
V_49 = F_31 ( V_48 , V_47 ) ;
if ( V_49 == - V_54 )
break;
if ( V_49 ) {
F_30 ( L_4 , V_3 -> V_6 ) ;
break;
}
}
return V_49 ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_27 * V_28 ;
bool V_55 , V_56 ;
struct V_7 * V_33 ;
int V_49 ;
F_34 ( L_5 , V_3 -> V_6 ) ;
if ( ! V_14 -> V_35 || ! V_14 -> V_40 )
return;
V_28 = & V_14 -> V_15 ;
V_56 = F_35 ( V_3 -> V_20 -> V_21 , V_28 -> V_57 ) ;
V_55 = V_3 -> V_20 -> V_21 -> type == V_58 ;
V_49 = F_36 ( V_3 -> V_6 , V_28 , V_55 , V_56 ) ;
if ( V_49 ) {
F_30 ( L_6 , V_3 -> V_6 ) ;
V_14 -> V_35 = false ;
F_37 ( V_3 -> V_6 , false ) ;
return;
}
V_33 = F_2 ( V_3 -> V_20 ) ;
V_14 -> V_40 = false ;
if ( V_33 -> V_38 )
V_14 -> V_41 = true ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_7 * V_33 ;
F_34 ( L_5 , V_3 -> V_6 ) ;
if ( ! V_14 -> V_42 )
return;
F_37 ( V_3 -> V_6 , V_14 -> V_35 ) ;
F_39 ( V_3 -> V_6 , V_14 -> V_59 ) ;
F_40 ( V_3 -> V_6 , V_14 -> V_60 , V_14 -> V_61 ) ;
V_33 = F_2 ( V_3 -> V_20 ) ;
V_14 -> V_42 = false ;
if ( V_33 -> V_38 )
V_14 -> V_43 = true ;
}
static void F_41 ( struct V_8 * V_9 )
{
struct V_7 * V_33 = F_2 ( V_9 ) ;
struct V_2 * V_3 ;
F_34 ( L_5 , V_9 -> V_6 ) ;
if ( ! V_33 -> V_35 )
return;
F_27 ( V_33 -> V_39 ) ;
F_10 (ovl, &mgr->overlays, list) {
F_33 ( V_3 ) ;
F_38 ( V_3 ) ;
}
if ( V_33 -> V_40 ) {
F_42 ( V_9 -> V_6 , & V_33 -> V_15 ) ;
V_33 -> V_40 = false ;
if ( V_33 -> V_38 )
V_33 -> V_41 = true ;
}
}
static void F_43 ( void )
{
const int V_37 = F_44 () ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_37 ; ++ V_12 ) {
struct V_8 * V_9 ;
struct V_7 * V_33 ;
int V_49 ;
V_9 = F_16 ( V_12 ) ;
V_33 = F_2 ( V_9 ) ;
if ( ! V_33 -> V_35 || F_8 ( V_9 ) || V_33 -> V_39 )
continue;
V_49 = F_12 ( V_9 , V_9 -> V_21 ) ;
if ( V_49 ) {
F_30 ( L_7
L_8 , V_9 -> V_62 ) ;
continue;
}
F_41 ( V_9 ) ;
}
}
static void F_45 ( void )
{
const int V_37 = F_44 () ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_37 ; ++ V_12 ) {
struct V_8 * V_9 ;
struct V_7 * V_33 ;
V_9 = F_16 ( V_12 ) ;
V_33 = F_2 ( V_9 ) ;
if ( ! V_33 -> V_35 || F_8 ( V_9 ) || V_33 -> V_39 )
continue;
if ( ! F_17 ( V_9 ) )
continue;
V_33 -> V_39 = true ;
if ( ! V_4 . V_63 && F_14 () )
F_46 () ;
F_47 ( V_9 -> V_6 ) ;
}
}
void F_48 ( struct V_8 * V_9 )
{
struct V_7 * V_33 = F_2 ( V_9 ) ;
unsigned long V_44 ;
int V_49 ;
F_22 ( & V_13 , V_44 ) ;
F_27 ( V_33 -> V_38 ) ;
V_49 = F_12 ( V_9 , V_9 -> V_21 ) ;
if ( V_49 ) {
F_30 ( L_9 ) ;
F_23 ( & V_13 , V_44 ) ;
return;
}
F_41 ( V_9 ) ;
V_33 -> V_38 = true ;
if ( ! V_4 . V_63 && F_14 () )
F_46 () ;
F_49 ( V_9 -> V_6 , true ) ;
F_23 ( & V_13 , V_44 ) ;
}
static void F_46 ( void )
{
const int V_37 = F_15 () ;
T_1 V_64 ;
int V_49 , V_12 ;
V_64 = 0 ;
for ( V_12 = 0 ; V_12 < V_37 ; ++ V_12 )
V_64 |= F_29 ( V_12 ) ;
for ( V_12 = 0 ; V_12 < V_37 ; ++ V_12 )
V_64 |= F_50 ( V_12 ) ;
V_49 = F_51 ( V_65 , NULL , V_64 ) ;
F_27 ( V_49 ) ;
V_4 . V_63 = true ;
}
static void F_52 ( void )
{
const int V_37 = F_15 () ;
T_1 V_64 ;
int V_49 , V_12 ;
V_64 = 0 ;
for ( V_12 = 0 ; V_12 < V_37 ; ++ V_12 )
V_64 |= F_29 ( V_12 ) ;
for ( V_12 = 0 ; V_12 < V_37 ; ++ V_12 )
V_64 |= F_50 ( V_12 ) ;
V_49 = F_53 ( V_65 , NULL , V_64 ) ;
F_27 ( V_49 ) ;
V_4 . V_63 = false ;
}
static void F_54 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_7 * V_33 ;
struct V_1 * V_14 ;
V_33 = F_2 ( V_9 ) ;
V_33 -> V_41 = false ;
F_10 (ovl, &mgr->overlays, list) {
V_14 = F_1 ( V_3 ) ;
V_14 -> V_41 = false ;
V_14 -> V_43 = false ;
}
}
static void V_65 ( void * V_66 , T_1 V_64 )
{
const int V_37 = F_15 () ;
int V_12 ;
bool V_67 ;
F_55 ( & V_13 ) ;
for ( V_12 = 0 ; V_12 < V_37 ; V_12 ++ ) {
struct V_8 * V_9 ;
struct V_7 * V_33 ;
bool V_68 ;
V_9 = F_16 ( V_12 ) ;
V_33 = F_2 ( V_9 ) ;
if ( ! V_33 -> V_35 )
continue;
V_68 = V_33 -> V_38 ;
V_33 -> V_38 = F_56 ( V_12 ) ;
if ( ! F_8 ( V_9 ) ) {
bool V_69 = V_33 -> V_39 ;
V_33 -> V_39 = F_57 ( V_12 ) ;
if ( V_69 && ! V_33 -> V_39 )
F_54 ( V_9 ) ;
} else {
if ( V_68 && ! V_33 -> V_38 )
F_54 ( V_9 ) ;
}
}
F_43 () ;
F_45 () ;
V_67 = F_18 () ;
if ( ! V_67 )
F_58 ( & V_46 ) ;
if ( ! F_14 () )
F_52 () ;
F_59 ( & V_13 ) ;
}
static void F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_14 ;
V_14 = F_1 ( V_3 ) ;
if ( ! V_14 -> V_34 )
return;
V_14 -> V_34 = false ;
V_14 -> V_40 = true ;
V_14 -> V_15 = V_14 -> V_19 ;
}
static void F_61 ( struct V_8 * V_9 )
{
struct V_7 * V_33 ;
V_33 = F_2 ( V_9 ) ;
if ( ! V_33 -> V_34 )
return;
V_33 -> V_34 = false ;
V_33 -> V_40 = true ;
V_33 -> V_15 = V_33 -> V_19 ;
}
int F_62 ( struct V_8 * V_9 )
{
unsigned long V_44 ;
struct V_2 * V_3 ;
int V_49 ;
F_63 ( L_10 , V_9 -> V_62 ) ;
F_22 ( & V_13 , V_44 ) ;
V_49 = F_13 ( V_9 , V_9 -> V_21 ) ;
if ( V_49 ) {
F_23 ( & V_13 , V_44 ) ;
F_30 ( L_11 ) ;
return V_49 ;
}
F_10 (ovl, &mgr->overlays, list)
F_60 ( V_3 ) ;
F_61 ( V_9 ) ;
F_43 () ;
F_45 () ;
F_23 ( & V_13 , V_44 ) ;
return 0 ;
}
static void F_64 ( struct V_2 * V_3 , bool V_70 )
{
struct V_1 * V_14 ;
V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_35 == V_70 )
return;
V_14 -> V_35 = V_70 ;
V_14 -> V_42 = true ;
}
static void F_65 ( struct V_2 * V_3 ,
T_1 V_60 , T_1 V_61 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
if ( V_14 -> V_60 == V_60 && V_14 -> V_61 == V_61 )
return;
V_14 -> V_60 = V_60 ;
V_14 -> V_61 = V_61 ;
V_14 -> V_42 = true ;
}
static void F_66 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_24 * V_25 ;
T_1 V_71 , V_72 ;
T_1 V_60 , V_61 ;
if ( ! V_14 -> V_35 && ! V_14 -> V_36 )
return;
V_25 = V_3 -> V_20 -> V_21 ;
V_71 = F_67 ( V_3 -> V_6 ) ;
V_72 = F_68 ( V_3 -> V_6 ) ;
switch ( V_25 -> type ) {
case V_73 :
case V_74 :
case V_75 :
case V_58 :
case V_76 :
F_69 ( V_3 -> V_6 , V_71 ,
V_72 , & V_60 , & V_61 ) ;
break;
#ifdef F_70
case V_77 :
F_71 ( V_3 -> V_6 , V_71 ,
V_72 , & V_60 , & V_61 ) ;
break;
#endif
default:
F_72 () ;
}
F_65 ( V_3 , V_60 , V_61 ) ;
}
static void F_73 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_7 * V_33 ;
V_33 = F_2 ( V_9 ) ;
if ( ! V_33 -> V_35 )
return;
F_10 (ovl, &mgr->overlays, list)
F_66 ( V_3 ) ;
}
static void F_74 ( void )
{
const int V_37 = F_44 () ;
struct V_8 * V_9 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_37 ; ++ V_12 ) {
V_9 = F_16 ( V_12 ) ;
F_73 ( V_9 ) ;
}
}
int F_75 ( struct V_8 * V_9 )
{
struct V_7 * V_33 = F_2 ( V_9 ) ;
unsigned long V_44 ;
int V_49 ;
F_76 ( & V_78 ) ;
if ( V_33 -> V_35 )
goto V_79;
F_22 ( & V_13 , V_44 ) ;
V_33 -> V_35 = true ;
V_49 = F_12 ( V_9 , V_9 -> V_21 ) ;
if ( V_49 ) {
F_30 ( L_12 ,
V_9 -> V_6 ) ;
goto V_80;
}
F_74 () ;
F_43 () ;
F_45 () ;
if ( ! F_8 ( V_9 ) )
V_33 -> V_38 = true ;
F_23 ( & V_13 , V_44 ) ;
if ( ! F_8 ( V_9 ) )
F_49 ( V_9 -> V_6 , true ) ;
V_79:
F_77 ( & V_78 ) ;
return 0 ;
V_80:
V_33 -> V_35 = false ;
F_23 ( & V_13 , V_44 ) ;
F_77 ( & V_78 ) ;
return V_49 ;
}
void F_78 ( struct V_8 * V_9 )
{
struct V_7 * V_33 = F_2 ( V_9 ) ;
unsigned long V_44 ;
F_76 ( & V_78 ) ;
if ( ! V_33 -> V_35 )
goto V_79;
if ( ! F_8 ( V_9 ) )
F_49 ( V_9 -> V_6 , false ) ;
F_22 ( & V_13 , V_44 ) ;
V_33 -> V_38 = false ;
V_33 -> V_35 = false ;
F_23 ( & V_13 , V_44 ) ;
V_79:
F_77 ( & V_78 ) ;
}
int F_79 ( struct V_8 * V_9 ,
struct V_29 * V_15 )
{
struct V_7 * V_33 = F_2 ( V_9 ) ;
unsigned long V_44 ;
int V_49 ;
V_49 = F_80 ( V_9 , V_15 ) ;
if ( V_49 )
return V_49 ;
F_22 ( & V_13 , V_44 ) ;
V_33 -> V_19 = * V_15 ;
V_33 -> V_34 = true ;
F_23 ( & V_13 , V_44 ) ;
return 0 ;
}
void F_81 ( struct V_8 * V_9 ,
struct V_29 * V_15 )
{
struct V_7 * V_33 = F_2 ( V_9 ) ;
unsigned long V_44 ;
F_22 ( & V_13 , V_44 ) ;
* V_15 = V_33 -> V_19 ;
F_23 ( & V_13 , V_44 ) ;
}
int F_82 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
int V_49 ;
F_76 ( & V_78 ) ;
if ( V_25 -> V_20 ) {
F_30 ( L_13 ,
V_25 -> V_62 , V_25 -> V_20 -> V_62 ) ;
V_49 = - V_81 ;
goto V_80;
}
if ( ( V_9 -> V_82 & V_25 -> type ) == 0 ) {
F_30 ( L_14 ,
V_25 -> V_62 , V_9 -> V_62 ) ;
V_49 = - V_81 ;
goto V_80;
}
V_25 -> V_20 = V_9 ;
V_9 -> V_21 = V_25 ;
F_77 ( & V_78 ) ;
return 0 ;
V_80:
F_77 ( & V_78 ) ;
return V_49 ;
}
int F_83 ( struct V_8 * V_9 )
{
int V_49 ;
F_76 ( & V_78 ) ;
if ( ! V_9 -> V_21 ) {
F_30 ( L_15 ) ;
V_49 = - V_81 ;
goto V_80;
}
if ( V_9 -> V_21 -> V_50 != V_83 ) {
V_49 = - V_81 ;
goto V_80;
}
V_9 -> V_21 -> V_20 = NULL ;
V_9 -> V_21 = NULL ;
F_77 ( & V_78 ) ;
return 0 ;
V_80:
F_77 ( & V_78 ) ;
return V_49 ;
}
int F_84 ( struct V_2 * V_3 ,
struct V_27 * V_15 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_44 ;
int V_49 ;
V_49 = F_85 ( V_3 , V_15 ) ;
if ( V_49 )
return V_49 ;
F_22 ( & V_13 , V_44 ) ;
V_14 -> V_19 = * V_15 ;
V_14 -> V_34 = true ;
F_23 ( & V_13 , V_44 ) ;
return 0 ;
}
void F_86 ( struct V_2 * V_3 ,
struct V_27 * V_15 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_44 ;
F_22 ( & V_13 , V_44 ) ;
* V_15 = V_14 -> V_19 ;
F_23 ( & V_13 , V_44 ) ;
}
int F_87 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_44 ;
int V_49 ;
if ( ! V_9 )
return - V_81 ;
F_76 ( & V_78 ) ;
if ( V_3 -> V_20 ) {
F_30 ( L_16 ,
V_3 -> V_62 , V_3 -> V_20 -> V_62 ) ;
V_49 = - V_81 ;
goto V_80;
}
F_22 ( & V_13 , V_44 ) ;
if ( V_14 -> V_35 ) {
F_23 ( & V_13 , V_44 ) ;
F_30 ( L_17 ) ;
V_49 = - V_81 ;
goto V_80;
}
V_14 -> V_59 = V_9 -> V_6 ;
V_14 -> V_42 = true ;
V_3 -> V_20 = V_9 ;
F_88 ( & V_3 -> V_84 , & V_9 -> V_85 ) ;
F_23 ( & V_13 , V_44 ) ;
F_77 ( & V_78 ) ;
return 0 ;
V_80:
F_77 ( & V_78 ) ;
return V_49 ;
}
int F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_44 ;
int V_49 ;
F_76 ( & V_78 ) ;
if ( ! V_3 -> V_20 ) {
F_30 ( L_18 ) ;
V_49 = - V_81 ;
goto V_80;
}
F_22 ( & V_13 , V_44 ) ;
if ( V_14 -> V_35 ) {
F_23 ( & V_13 , V_44 ) ;
F_30 ( L_19 ) ;
V_49 = - V_81 ;
goto V_80;
}
V_14 -> V_59 = - 1 ;
V_3 -> V_20 = NULL ;
F_90 ( & V_3 -> V_84 ) ;
F_23 ( & V_13 , V_44 ) ;
F_77 ( & V_78 ) ;
return 0 ;
V_80:
F_77 ( & V_78 ) ;
return V_49 ;
}
bool F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_44 ;
bool V_86 ;
F_22 ( & V_13 , V_44 ) ;
V_86 = V_14 -> V_35 ;
F_23 ( & V_13 , V_44 ) ;
return V_86 ;
}
int F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_44 ;
int V_49 ;
F_76 ( & V_78 ) ;
if ( V_14 -> V_35 ) {
V_49 = 0 ;
goto V_87;
}
if ( V_3 -> V_20 == NULL || V_3 -> V_20 -> V_21 == NULL ) {
V_49 = - V_81 ;
goto V_87;
}
F_22 ( & V_13 , V_44 ) ;
V_14 -> V_36 = true ;
V_49 = F_12 ( V_3 -> V_20 , V_3 -> V_20 -> V_21 ) ;
if ( V_49 ) {
F_30 ( L_20 ,
V_3 -> V_6 ) ;
goto V_88;
}
F_74 () ;
V_14 -> V_36 = false ;
F_64 ( V_3 , true ) ;
F_43 () ;
F_45 () ;
F_23 ( & V_13 , V_44 ) ;
F_21 () ;
F_77 ( & V_78 ) ;
return 0 ;
V_88:
V_14 -> V_36 = false ;
F_23 ( & V_13 , V_44 ) ;
V_87:
F_77 ( & V_78 ) ;
return V_49 ;
}
int F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
unsigned long V_44 ;
int V_49 ;
F_76 ( & V_78 ) ;
if ( ! V_14 -> V_35 ) {
V_49 = 0 ;
goto V_80;
}
if ( V_3 -> V_20 == NULL || V_3 -> V_20 -> V_21 == NULL ) {
V_49 = - V_81 ;
goto V_80;
}
F_22 ( & V_13 , V_44 ) ;
F_64 ( V_3 , false ) ;
F_43 () ;
F_45 () ;
F_23 ( & V_13 , V_44 ) ;
F_21 () ;
F_77 ( & V_78 ) ;
return 0 ;
V_80:
F_77 ( & V_78 ) ;
return V_49 ;
}
