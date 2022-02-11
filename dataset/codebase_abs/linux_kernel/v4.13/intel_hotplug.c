bool F_1 ( enum V_1 V_2 , enum V_3 * V_3 )
{
switch ( V_2 ) {
case V_4 :
* V_3 = V_5 ;
return true ;
case V_6 :
* V_3 = V_7 ;
return true ;
case V_8 :
* V_3 = V_9 ;
return true ;
case V_10 :
* V_3 = V_11 ;
return true ;
case V_12 :
* V_3 = V_13 ;
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_14 * V_15 ,
enum V_1 V_2 )
{
unsigned long V_16 = V_15 -> V_17 . V_18 [ V_2 ] . V_19 ;
unsigned long V_20 = V_16 + F_3 ( V_21 ) ;
const int V_22 = V_15 -> V_17 . V_23 ;
bool V_24 = false ;
if ( ! F_4 ( V_25 , V_16 , V_20 ) ) {
V_15 -> V_17 . V_18 [ V_2 ] . V_19 = V_25 ;
V_15 -> V_17 . V_18 [ V_2 ] . V_26 = 0 ;
F_5 ( L_1 , V_2 ) ;
} else if ( V_15 -> V_17 . V_18 [ V_2 ] . V_26 > V_22 &&
V_22 ) {
V_15 -> V_17 . V_18 [ V_2 ] . V_27 = V_28 ;
F_5 ( L_2 , V_2 ) ;
V_24 = true ;
} else {
V_15 -> V_17 . V_18 [ V_2 ] . V_26 ++ ;
F_5 ( L_3 , V_2 ,
V_15 -> V_17 . V_18 [ V_2 ] . V_26 ) ;
}
return V_24 ;
}
static void F_6 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = & V_15 -> V_31 ;
struct V_32 * V_32 ;
struct V_33 * V_33 ;
struct V_34 * V_35 ;
struct V_36 V_37 ;
enum V_1 V_2 ;
bool V_38 = false ;
F_7 ( & V_15 -> V_39 ) ;
F_8 ( V_30 , & V_37 ) ;
F_9 (connector, &conn_iter) {
if ( V_35 -> V_40 != V_41 )
continue;
V_32 = F_10 ( V_35 ) ;
V_33 = V_32 -> V_42 ;
if ( ! V_33 )
continue;
V_2 = V_33 -> V_1 ;
if ( V_2 == V_43 ||
V_15 -> V_17 . V_18 [ V_2 ] . V_27 != V_28 )
continue;
F_11 ( L_4
L_5 ,
V_35 -> V_44 ) ;
V_15 -> V_17 . V_18 [ V_2 ] . V_27 = V_45 ;
V_35 -> V_40 = V_46
| V_47 ;
V_38 = true ;
}
F_12 ( & V_37 ) ;
if ( V_38 ) {
F_13 ( V_30 ) ;
F_14 ( V_48 , & V_15 -> V_17 . V_49 ,
F_3 ( V_50 ) ) ;
}
}
static void F_15 ( struct V_51 * V_52 )
{
struct V_14 * V_15 =
F_16 ( V_52 , F_17 ( * V_15 ) ,
V_17 . V_49 . V_52 ) ;
struct V_29 * V_30 = & V_15 -> V_31 ;
int V_53 ;
F_18 ( V_15 ) ;
F_19 ( & V_15 -> V_39 ) ;
F_20 (i) {
struct V_34 * V_35 ;
struct V_36 V_37 ;
if ( V_15 -> V_17 . V_18 [ V_53 ] . V_27 != V_45 )
continue;
V_15 -> V_17 . V_18 [ V_53 ] . V_27 = V_54 ;
F_8 ( V_30 , & V_37 ) ;
F_9 (connector, &conn_iter) {
struct V_32 * V_32 = F_10 ( V_35 ) ;
if ( V_32 -> V_42 -> V_1 == V_53 ) {
if ( V_35 -> V_40 != V_32 -> V_40 )
F_21 ( L_6 ,
V_35 -> V_44 ) ;
V_35 -> V_40 = V_32 -> V_40 ;
if ( ! V_35 -> V_40 )
V_35 -> V_40 = V_41 ;
}
}
F_12 ( & V_37 ) ;
}
if ( V_15 -> V_55 && V_15 -> V_56 . V_57 )
V_15 -> V_56 . V_57 ( V_15 ) ;
F_22 ( & V_15 -> V_39 ) ;
F_23 ( V_15 ) ;
}
static bool F_24 ( struct V_29 * V_30 ,
struct V_34 * V_35 )
{
enum V_58 V_59 ;
F_25 ( ! F_26 ( & V_30 -> V_60 . V_61 ) ) ;
V_59 = V_35 -> V_62 ;
V_35 -> V_62 = F_27 ( V_35 , NULL , false ) ;
if ( V_59 == V_35 -> V_62 )
return false ;
F_5 ( L_7 ,
V_35 -> V_63 . V_64 ,
V_35 -> V_44 ,
F_28 ( V_59 ) ,
F_28 ( V_35 -> V_62 ) ) ;
return true ;
}
static void F_29 ( struct V_51 * V_52 )
{
struct V_14 * V_15 =
F_16 ( V_52 , struct V_14 , V_17 . V_65 ) ;
T_1 V_66 , V_67 ;
struct V_68 * V_69 ;
int V_53 ;
T_1 V_70 = 0 ;
F_19 ( & V_15 -> V_39 ) ;
V_66 = V_15 -> V_17 . V_66 ;
V_15 -> V_17 . V_66 = 0 ;
V_67 = V_15 -> V_17 . V_67 ;
V_15 -> V_17 . V_67 = 0 ;
F_22 ( & V_15 -> V_39 ) ;
for ( V_53 = 0 ; V_53 < V_71 ; V_53 ++ ) {
bool V_72 = false ;
bool V_73 = false ;
V_69 = V_15 -> V_17 . V_74 [ V_53 ] ;
if ( ! V_69 || ! V_69 -> V_75 )
continue;
if ( V_66 & ( 1 << V_53 ) ) {
V_72 = true ;
V_73 = true ;
} else if ( V_67 & ( 1 << V_53 ) )
V_72 = true ;
if ( V_72 ) {
enum V_76 V_77 ;
V_77 = V_69 -> V_75 ( V_69 , V_73 ) ;
if ( V_77 == V_78 ) {
V_70 |= ( 1 << V_69 -> V_63 . V_1 ) ;
}
}
}
if ( V_70 ) {
F_19 ( & V_15 -> V_39 ) ;
V_15 -> V_17 . V_79 |= V_70 ;
F_22 ( & V_15 -> V_39 ) ;
F_30 ( & V_15 -> V_17 . V_80 ) ;
}
}
static void F_31 ( struct V_51 * V_52 )
{
struct V_14 * V_15 =
F_16 ( V_52 , struct V_14 , V_17 . V_80 ) ;
struct V_29 * V_30 = & V_15 -> V_31 ;
struct V_32 * V_32 ;
struct V_33 * V_33 ;
struct V_34 * V_35 ;
struct V_36 V_37 ;
bool V_81 = false ;
T_1 V_82 ;
F_32 ( & V_30 -> V_60 . V_61 ) ;
F_5 ( L_8 ) ;
F_19 ( & V_15 -> V_39 ) ;
V_82 = V_15 -> V_17 . V_79 ;
V_15 -> V_17 . V_79 = 0 ;
F_6 ( V_15 ) ;
F_22 ( & V_15 -> V_39 ) ;
F_8 ( V_30 , & V_37 ) ;
F_9 (connector, &conn_iter) {
V_32 = F_10 ( V_35 ) ;
if ( ! V_32 -> V_42 )
continue;
V_33 = V_32 -> V_42 ;
if ( V_82 & ( 1 << V_33 -> V_1 ) ) {
F_5 ( L_9 ,
V_35 -> V_44 , V_33 -> V_1 ) ;
if ( V_33 -> V_83 )
V_33 -> V_83 ( V_33 ) ;
if ( F_24 ( V_30 , V_35 ) )
V_81 = true ;
}
}
F_12 ( & V_37 ) ;
F_33 ( & V_30 -> V_60 . V_61 ) ;
if ( V_81 )
F_34 ( V_30 ) ;
}
void F_35 ( struct V_14 * V_15 ,
T_1 V_84 , T_1 V_85 )
{
int V_53 ;
enum V_3 V_3 ;
bool V_86 = false ;
bool V_87 = false , V_88 = false ;
bool V_89 ;
if ( ! V_84 )
return;
F_36 ( & V_15 -> V_39 ) ;
F_20 (i) {
if ( ! ( F_37 ( V_53 ) & V_84 ) )
continue;
V_89 = F_1 ( V_53 , & V_3 ) &&
V_15 -> V_17 . V_74 [ V_3 ] ;
if ( V_89 ) {
bool V_73 = V_85 & F_37 ( V_53 ) ;
F_21 ( L_10 , F_38 ( V_3 ) ,
V_73 ? L_11 : L_12 ) ;
V_87 = true ;
if ( V_73 ) {
V_15 -> V_17 . V_66 |= ( 1 << V_3 ) ;
} else {
V_15 -> V_17 . V_67 |= ( 1 << V_3 ) ;
continue;
}
}
if ( V_15 -> V_17 . V_18 [ V_53 ] . V_27 == V_45 ) {
F_39 ( ! F_40 ( V_15 ) ,
L_13 , V_53 ) ;
continue;
}
if ( V_15 -> V_17 . V_18 [ V_53 ] . V_27 != V_54 )
continue;
if ( ! V_89 ) {
V_15 -> V_17 . V_79 |= F_37 ( V_53 ) ;
V_88 = true ;
}
if ( F_2 ( V_15 , V_53 ) ) {
V_15 -> V_17 . V_79 &= ~ F_37 ( V_53 ) ;
V_86 = true ;
}
}
if ( V_86 && V_15 -> V_55 )
V_15 -> V_56 . V_57 ( V_15 ) ;
F_41 ( & V_15 -> V_39 ) ;
if ( V_87 )
F_42 ( V_15 -> V_17 . V_90 , & V_15 -> V_17 . V_65 ) ;
if ( V_88 )
F_30 ( & V_15 -> V_17 . V_80 ) ;
}
void F_43 ( struct V_14 * V_15 )
{
int V_53 ;
F_20 (i) {
V_15 -> V_17 . V_18 [ V_53 ] . V_26 = 0 ;
V_15 -> V_17 . V_18 [ V_53 ] . V_27 = V_54 ;
}
F_44 ( V_15 -> V_17 . V_91 , false ) ;
F_30 ( & V_15 -> V_17 . V_92 ) ;
if ( V_15 -> V_55 && V_15 -> V_56 . V_57 ) {
F_19 ( & V_15 -> V_39 ) ;
if ( V_15 -> V_55 )
V_15 -> V_56 . V_57 ( V_15 ) ;
F_22 ( & V_15 -> V_39 ) ;
}
}
static void F_45 ( struct V_51 * V_52 )
{
struct V_14 * V_15 =
F_16 ( V_52 , struct V_14 ,
V_17 . V_92 ) ;
struct V_29 * V_30 = & V_15 -> V_31 ;
struct V_34 * V_35 ;
struct V_36 V_37 ;
bool V_93 ;
F_32 ( & V_30 -> V_60 . V_61 ) ;
V_93 = F_46 ( V_15 -> V_17 . V_91 ) ;
F_8 ( V_30 , & V_37 ) ;
F_9 (connector, &conn_iter) {
struct V_32 * V_32 =
F_10 ( V_35 ) ;
V_35 -> V_40 = V_32 -> V_40 ;
if ( V_32 -> V_94 )
continue;
if ( ! V_35 -> V_40 && F_47 ( V_15 ) &&
V_32 -> V_42 -> V_1 > V_43 ) {
V_35 -> V_40 = V_93 ?
V_46 |
V_47 :
V_41 ;
}
}
F_12 ( & V_37 ) ;
if ( V_93 )
F_13 ( V_30 ) ;
F_33 ( & V_30 -> V_60 . V_61 ) ;
if ( ! V_93 )
F_48 ( V_30 ) ;
}
void F_49 ( struct V_14 * V_15 )
{
F_44 ( V_15 -> V_17 . V_91 , true ) ;
F_30 ( & V_15 -> V_17 . V_92 ) ;
}
void F_50 ( struct V_14 * V_15 )
{
F_51 ( & V_15 -> V_17 . V_80 , F_31 ) ;
F_51 ( & V_15 -> V_17 . V_65 , F_29 ) ;
F_51 ( & V_15 -> V_17 . V_92 , F_45 ) ;
F_52 ( & V_15 -> V_17 . V_49 ,
F_15 ) ;
}
void F_53 ( struct V_14 * V_15 )
{
F_19 ( & V_15 -> V_39 ) ;
V_15 -> V_17 . V_66 = 0 ;
V_15 -> V_17 . V_67 = 0 ;
V_15 -> V_17 . V_79 = 0 ;
F_22 ( & V_15 -> V_39 ) ;
F_54 ( & V_15 -> V_17 . V_65 ) ;
F_54 ( & V_15 -> V_17 . V_80 ) ;
F_54 ( & V_15 -> V_17 . V_92 ) ;
F_55 ( & V_15 -> V_17 . V_49 ) ;
}
bool F_56 ( struct V_14 * V_15 , enum V_1 V_2 )
{
bool V_77 = false ;
if ( V_2 == V_43 )
return false ;
F_19 ( & V_15 -> V_39 ) ;
if ( V_15 -> V_17 . V_18 [ V_2 ] . V_27 == V_54 ) {
V_15 -> V_17 . V_18 [ V_2 ] . V_27 = V_45 ;
V_77 = true ;
}
F_22 ( & V_15 -> V_39 ) ;
return V_77 ;
}
void F_57 ( struct V_14 * V_15 , enum V_1 V_2 )
{
if ( V_2 == V_43 )
return;
F_19 ( & V_15 -> V_39 ) ;
V_15 -> V_17 . V_18 [ V_2 ] . V_27 = V_54 ;
F_22 ( & V_15 -> V_39 ) ;
}
