enum V_1 F_1 ( enum V_2 V_3 )
{
switch ( V_3 ) {
case V_4 :
return V_5 ;
case V_6 :
return V_7 ;
case V_8 :
return V_9 ;
case V_10 :
return V_11 ;
case V_12 :
return V_13 ;
default:
return V_14 ;
}
}
enum V_2 F_2 ( enum V_1 V_1 )
{
switch ( V_1 ) {
case V_5 :
return V_4 ;
case V_7 :
return V_6 ;
case V_9 :
return V_8 ;
case V_11 :
return V_10 ;
case V_13 :
return V_12 ;
default:
F_3 ( V_1 ) ;
return V_15 ;
}
}
static bool F_4 ( struct V_16 * V_17 ,
enum V_2 V_3 )
{
unsigned long V_18 = V_17 -> V_19 . V_20 [ V_3 ] . V_21 ;
unsigned long V_22 = V_18 + F_5 ( V_23 ) ;
const int V_24 = V_17 -> V_19 . V_25 ;
bool V_26 = false ;
if ( ! F_6 ( V_27 , V_18 , V_22 ) ) {
V_17 -> V_19 . V_20 [ V_3 ] . V_21 = V_27 ;
V_17 -> V_19 . V_20 [ V_3 ] . V_28 = 0 ;
F_7 ( L_1 , V_3 ) ;
} else if ( V_17 -> V_19 . V_20 [ V_3 ] . V_28 > V_24 &&
V_24 ) {
V_17 -> V_19 . V_20 [ V_3 ] . V_29 = V_30 ;
F_7 ( L_2 , V_3 ) ;
V_26 = true ;
} else {
V_17 -> V_19 . V_20 [ V_3 ] . V_28 ++ ;
F_7 ( L_3 , V_3 ,
V_17 -> V_19 . V_20 [ V_3 ] . V_28 ) ;
}
return V_26 ;
}
static void F_8 ( struct V_16 * V_17 )
{
struct V_31 * V_32 = & V_17 -> V_33 ;
struct V_34 * V_34 ;
struct V_35 * V_35 ;
struct V_36 * V_37 ;
struct V_38 V_39 ;
enum V_2 V_3 ;
bool V_40 = false ;
F_9 ( & V_17 -> V_41 ) ;
F_10 ( V_32 , & V_39 ) ;
F_11 (connector, &conn_iter) {
if ( V_37 -> V_42 != V_43 )
continue;
V_34 = F_12 ( V_37 ) ;
V_35 = V_34 -> V_44 ;
if ( ! V_35 )
continue;
V_3 = V_35 -> V_2 ;
if ( V_3 == V_15 ||
V_17 -> V_19 . V_20 [ V_3 ] . V_29 != V_30 )
continue;
F_13 ( L_4
L_5 ,
V_37 -> V_45 ) ;
V_17 -> V_19 . V_20 [ V_3 ] . V_29 = V_46 ;
V_37 -> V_42 = V_47
| V_48 ;
V_40 = true ;
}
F_14 ( & V_39 ) ;
if ( V_40 ) {
F_15 ( V_32 ) ;
F_16 ( V_49 , & V_17 -> V_19 . V_50 ,
F_5 ( V_51 ) ) ;
}
}
static void F_17 ( struct V_52 * V_53 )
{
struct V_16 * V_17 =
F_18 ( V_53 , F_19 ( * V_17 ) ,
V_19 . V_50 . V_53 ) ;
struct V_31 * V_32 = & V_17 -> V_33 ;
int V_54 ;
F_20 ( V_17 ) ;
F_21 ( & V_17 -> V_41 ) ;
F_22 (i) {
struct V_36 * V_37 ;
struct V_38 V_39 ;
if ( V_17 -> V_19 . V_20 [ V_54 ] . V_29 != V_46 )
continue;
V_17 -> V_19 . V_20 [ V_54 ] . V_29 = V_55 ;
F_10 ( V_32 , & V_39 ) ;
F_11 (connector, &conn_iter) {
struct V_34 * V_34 = F_12 ( V_37 ) ;
if ( V_34 -> V_44 -> V_2 == V_54 ) {
if ( V_37 -> V_42 != V_34 -> V_42 )
F_23 ( L_6 ,
V_37 -> V_45 ) ;
V_37 -> V_42 = V_34 -> V_42 ;
if ( ! V_37 -> V_42 )
V_37 -> V_42 = V_43 ;
}
}
F_14 ( & V_39 ) ;
}
if ( V_17 -> V_56 && V_17 -> V_57 . V_58 )
V_17 -> V_57 . V_58 ( V_17 ) ;
F_24 ( & V_17 -> V_41 ) ;
F_25 ( V_17 ) ;
}
static bool F_26 ( struct V_31 * V_32 ,
struct V_36 * V_37 )
{
enum V_59 V_60 ;
F_27 ( ! F_28 ( & V_32 -> V_61 . V_62 ) ) ;
V_60 = V_37 -> V_63 ;
V_37 -> V_63 = F_29 ( V_37 , NULL , false ) ;
if ( V_60 == V_37 -> V_63 )
return false ;
F_7 ( L_7 ,
V_37 -> V_64 . V_65 ,
V_37 -> V_45 ,
F_30 ( V_60 ) ,
F_30 ( V_37 -> V_63 ) ) ;
return true ;
}
static void F_31 ( struct V_52 * V_53 )
{
struct V_16 * V_17 =
F_18 ( V_53 , struct V_16 , V_19 . V_66 ) ;
T_1 V_67 , V_68 ;
struct V_69 * V_70 ;
int V_54 ;
T_1 V_71 = 0 ;
F_21 ( & V_17 -> V_41 ) ;
V_67 = V_17 -> V_19 . V_67 ;
V_17 -> V_19 . V_67 = 0 ;
V_68 = V_17 -> V_19 . V_68 ;
V_17 -> V_19 . V_68 = 0 ;
F_24 ( & V_17 -> V_41 ) ;
for ( V_54 = 0 ; V_54 < V_72 ; V_54 ++ ) {
bool V_73 = false ;
bool V_74 = false ;
V_70 = V_17 -> V_19 . V_75 [ V_54 ] ;
if ( ! V_70 || ! V_70 -> V_76 )
continue;
if ( V_67 & ( 1 << V_54 ) ) {
V_73 = true ;
V_74 = true ;
} else if ( V_68 & ( 1 << V_54 ) )
V_73 = true ;
if ( V_73 ) {
enum V_77 V_78 ;
V_78 = V_70 -> V_76 ( V_70 , V_74 ) ;
if ( V_78 == V_79 ) {
V_71 |= ( 1 << V_70 -> V_64 . V_2 ) ;
}
}
}
if ( V_71 ) {
F_21 ( & V_17 -> V_41 ) ;
V_17 -> V_19 . V_80 |= V_71 ;
F_24 ( & V_17 -> V_41 ) ;
F_32 ( & V_17 -> V_19 . V_81 ) ;
}
}
static void F_33 ( struct V_52 * V_53 )
{
struct V_16 * V_17 =
F_18 ( V_53 , struct V_16 , V_19 . V_81 ) ;
struct V_31 * V_32 = & V_17 -> V_33 ;
struct V_34 * V_34 ;
struct V_35 * V_35 ;
struct V_36 * V_37 ;
struct V_38 V_39 ;
bool V_82 = false ;
T_1 V_83 ;
F_34 ( & V_32 -> V_61 . V_62 ) ;
F_7 ( L_8 ) ;
F_21 ( & V_17 -> V_41 ) ;
V_83 = V_17 -> V_19 . V_80 ;
V_17 -> V_19 . V_80 = 0 ;
F_8 ( V_17 ) ;
F_24 ( & V_17 -> V_41 ) ;
F_10 ( V_32 , & V_39 ) ;
F_11 (connector, &conn_iter) {
V_34 = F_12 ( V_37 ) ;
if ( ! V_34 -> V_44 )
continue;
V_35 = V_34 -> V_44 ;
if ( V_83 & ( 1 << V_35 -> V_2 ) ) {
F_7 ( L_9 ,
V_37 -> V_45 , V_35 -> V_2 ) ;
if ( V_35 -> V_84 )
V_35 -> V_84 ( V_35 ) ;
if ( F_26 ( V_32 , V_37 ) )
V_82 = true ;
}
}
F_14 ( & V_39 ) ;
F_35 ( & V_32 -> V_61 . V_62 ) ;
if ( V_82 )
F_36 ( V_32 ) ;
}
void F_37 ( struct V_16 * V_17 ,
T_1 V_85 , T_1 V_86 )
{
int V_54 ;
enum V_1 V_1 ;
bool V_87 = false ;
bool V_88 = false , V_89 = false ;
bool V_90 ;
if ( ! V_85 )
return;
F_38 ( & V_17 -> V_41 ) ;
F_22 (i) {
if ( ! ( F_39 ( V_54 ) & V_85 ) )
continue;
V_1 = F_1 ( V_54 ) ;
V_90 = V_1 != V_14 &&
V_17 -> V_19 . V_75 [ V_1 ] ;
if ( V_90 ) {
bool V_74 = V_86 & F_39 ( V_54 ) ;
F_23 ( L_10 , F_40 ( V_1 ) ,
V_74 ? L_11 : L_12 ) ;
V_88 = true ;
if ( V_74 ) {
V_17 -> V_19 . V_67 |= ( 1 << V_1 ) ;
} else {
V_17 -> V_19 . V_68 |= ( 1 << V_1 ) ;
continue;
}
}
if ( V_17 -> V_19 . V_20 [ V_54 ] . V_29 == V_46 ) {
F_41 ( ! F_42 ( V_17 ) ,
L_13 , V_54 ) ;
continue;
}
if ( V_17 -> V_19 . V_20 [ V_54 ] . V_29 != V_55 )
continue;
if ( ! V_90 ) {
V_17 -> V_19 . V_80 |= F_39 ( V_54 ) ;
V_89 = true ;
}
if ( F_4 ( V_17 , V_54 ) ) {
V_17 -> V_19 . V_80 &= ~ F_39 ( V_54 ) ;
V_87 = true ;
}
}
if ( V_87 && V_17 -> V_56 )
V_17 -> V_57 . V_58 ( V_17 ) ;
F_43 ( & V_17 -> V_41 ) ;
if ( V_88 )
F_44 ( V_17 -> V_19 . V_91 , & V_17 -> V_19 . V_66 ) ;
if ( V_89 )
F_32 ( & V_17 -> V_19 . V_81 ) ;
}
void F_45 ( struct V_16 * V_17 )
{
int V_54 ;
F_22 (i) {
V_17 -> V_19 . V_20 [ V_54 ] . V_28 = 0 ;
V_17 -> V_19 . V_20 [ V_54 ] . V_29 = V_55 ;
}
F_46 ( V_17 -> V_19 . V_92 , false ) ;
F_32 ( & V_17 -> V_19 . V_93 ) ;
if ( V_17 -> V_56 && V_17 -> V_57 . V_58 ) {
F_21 ( & V_17 -> V_41 ) ;
if ( V_17 -> V_56 )
V_17 -> V_57 . V_58 ( V_17 ) ;
F_24 ( & V_17 -> V_41 ) ;
}
}
static void F_47 ( struct V_52 * V_53 )
{
struct V_16 * V_17 =
F_18 ( V_53 , struct V_16 ,
V_19 . V_93 ) ;
struct V_31 * V_32 = & V_17 -> V_33 ;
struct V_36 * V_37 ;
struct V_38 V_39 ;
bool V_94 ;
F_34 ( & V_32 -> V_61 . V_62 ) ;
V_94 = F_48 ( V_17 -> V_19 . V_92 ) ;
F_10 ( V_32 , & V_39 ) ;
F_11 (connector, &conn_iter) {
struct V_34 * V_34 =
F_12 ( V_37 ) ;
V_37 -> V_42 = V_34 -> V_42 ;
if ( V_34 -> V_95 )
continue;
if ( ! V_37 -> V_42 && F_49 ( V_17 ) &&
V_34 -> V_44 -> V_2 > V_15 ) {
V_37 -> V_42 = V_94 ?
V_47 |
V_48 :
V_43 ;
}
}
F_14 ( & V_39 ) ;
if ( V_94 )
F_15 ( V_32 ) ;
F_35 ( & V_32 -> V_61 . V_62 ) ;
if ( ! V_94 )
F_50 ( V_32 ) ;
}
void F_51 ( struct V_16 * V_17 )
{
F_46 ( V_17 -> V_19 . V_92 , true ) ;
F_32 ( & V_17 -> V_19 . V_93 ) ;
}
void F_52 ( struct V_16 * V_17 )
{
F_53 ( & V_17 -> V_19 . V_81 , F_33 ) ;
F_53 ( & V_17 -> V_19 . V_66 , F_31 ) ;
F_53 ( & V_17 -> V_19 . V_93 , F_47 ) ;
F_54 ( & V_17 -> V_19 . V_50 ,
F_17 ) ;
}
void F_55 ( struct V_16 * V_17 )
{
F_21 ( & V_17 -> V_41 ) ;
V_17 -> V_19 . V_67 = 0 ;
V_17 -> V_19 . V_68 = 0 ;
V_17 -> V_19 . V_80 = 0 ;
F_24 ( & V_17 -> V_41 ) ;
F_56 ( & V_17 -> V_19 . V_66 ) ;
F_56 ( & V_17 -> V_19 . V_81 ) ;
F_56 ( & V_17 -> V_19 . V_93 ) ;
F_57 ( & V_17 -> V_19 . V_50 ) ;
}
bool F_58 ( struct V_16 * V_17 , enum V_2 V_3 )
{
bool V_78 = false ;
if ( V_3 == V_15 )
return false ;
F_21 ( & V_17 -> V_41 ) ;
if ( V_17 -> V_19 . V_20 [ V_3 ] . V_29 == V_55 ) {
V_17 -> V_19 . V_20 [ V_3 ] . V_29 = V_46 ;
V_78 = true ;
}
F_24 ( & V_17 -> V_41 ) ;
return V_78 ;
}
void F_59 ( struct V_16 * V_17 , enum V_2 V_3 )
{
if ( V_3 == V_15 )
return;
F_21 ( & V_17 -> V_41 ) ;
V_17 -> V_19 . V_20 [ V_3 ] . V_29 = V_55 ;
F_24 ( & V_17 -> V_41 ) ;
}
