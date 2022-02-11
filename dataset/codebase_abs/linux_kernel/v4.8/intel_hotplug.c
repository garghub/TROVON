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
bool V_22 = false ;
if ( ! F_4 ( V_23 , V_16 , V_20 ) ) {
V_15 -> V_17 . V_18 [ V_2 ] . V_19 = V_23 ;
V_15 -> V_17 . V_18 [ V_2 ] . V_24 = 0 ;
F_5 ( L_1 , V_2 ) ;
} else if ( V_15 -> V_17 . V_18 [ V_2 ] . V_24 > V_25 ) {
V_15 -> V_17 . V_18 [ V_2 ] . V_26 = V_27 ;
F_5 ( L_2 , V_2 ) ;
V_22 = true ;
} else {
V_15 -> V_17 . V_18 [ V_2 ] . V_24 ++ ;
F_5 ( L_3 , V_2 ,
V_15 -> V_17 . V_18 [ V_2 ] . V_24 ) ;
}
return V_22 ;
}
static void F_6 ( struct V_14 * V_15 )
{
struct V_28 * V_29 = & V_15 -> V_30 ;
struct V_31 * V_32 = & V_29 -> V_32 ;
struct V_33 * V_33 ;
struct V_34 * V_34 ;
struct V_35 * V_36 ;
enum V_1 V_2 ;
bool V_37 = false ;
F_7 ( & V_15 -> V_38 ) ;
F_8 (connector, &mode_config->connector_list, head) {
if ( V_36 -> V_39 != V_40 )
continue;
V_33 = F_9 ( V_36 ) ;
V_34 = V_33 -> V_41 ;
if ( ! V_34 )
continue;
V_2 = V_34 -> V_1 ;
if ( V_2 == V_42 ||
V_15 -> V_17 . V_18 [ V_2 ] . V_26 != V_27 )
continue;
F_10 ( L_4
L_5 ,
V_36 -> V_43 ) ;
V_15 -> V_17 . V_18 [ V_2 ] . V_26 = V_44 ;
V_36 -> V_39 = V_45
| V_46 ;
V_37 = true ;
}
if ( V_37 ) {
F_11 ( V_29 ) ;
F_12 ( V_47 , & V_15 -> V_17 . V_48 ,
F_3 ( V_49 ) ) ;
}
}
static void F_13 ( struct V_50 * V_51 )
{
struct V_14 * V_15 =
F_14 ( V_51 , F_15 ( * V_15 ) ,
V_17 . V_48 . V_51 ) ;
struct V_28 * V_29 = & V_15 -> V_30 ;
struct V_31 * V_32 = & V_29 -> V_32 ;
int V_52 ;
F_16 ( V_15 ) ;
F_17 ( & V_15 -> V_38 ) ;
F_18 (i) {
struct V_35 * V_36 ;
if ( V_15 -> V_17 . V_18 [ V_52 ] . V_26 != V_44 )
continue;
V_15 -> V_17 . V_18 [ V_52 ] . V_26 = V_53 ;
F_8 (connector, &mode_config->connector_list, head) {
struct V_33 * V_33 = F_9 ( V_36 ) ;
if ( V_33 -> V_41 -> V_1 == V_52 ) {
if ( V_36 -> V_39 != V_33 -> V_39 )
F_19 ( L_6 ,
V_36 -> V_43 ) ;
V_36 -> V_39 = V_33 -> V_39 ;
if ( ! V_36 -> V_39 )
V_36 -> V_39 = V_40 ;
}
}
}
if ( V_15 -> V_54 . V_55 )
V_15 -> V_54 . V_55 ( V_15 ) ;
F_20 ( & V_15 -> V_38 ) ;
F_21 ( V_15 ) ;
}
static bool F_22 ( struct V_28 * V_29 ,
struct V_35 * V_36 )
{
enum V_56 V_57 ;
F_23 ( ! F_24 ( & V_29 -> V_32 . V_58 ) ) ;
V_57 = V_36 -> V_59 ;
V_36 -> V_59 = V_36 -> V_60 -> V_61 ( V_36 , false ) ;
if ( V_57 == V_36 -> V_59 )
return false ;
F_5 ( L_7 ,
V_36 -> V_62 . V_63 ,
V_36 -> V_43 ,
F_25 ( V_57 ) ,
F_25 ( V_36 -> V_59 ) ) ;
return true ;
}
static void F_26 ( struct V_50 * V_51 )
{
struct V_14 * V_15 =
F_14 ( V_51 , struct V_14 , V_17 . V_64 ) ;
T_1 V_65 , V_66 ;
struct V_67 * V_68 ;
int V_52 ;
T_1 V_69 = 0 ;
F_17 ( & V_15 -> V_38 ) ;
V_65 = V_15 -> V_17 . V_65 ;
V_15 -> V_17 . V_65 = 0 ;
V_66 = V_15 -> V_17 . V_66 ;
V_15 -> V_17 . V_66 = 0 ;
F_20 ( & V_15 -> V_38 ) ;
for ( V_52 = 0 ; V_52 < V_70 ; V_52 ++ ) {
bool V_71 = false ;
bool V_72 = false ;
V_68 = V_15 -> V_17 . V_73 [ V_52 ] ;
if ( ! V_68 || ! V_68 -> V_74 )
continue;
if ( V_65 & ( 1 << V_52 ) ) {
V_71 = true ;
V_72 = true ;
} else if ( V_66 & ( 1 << V_52 ) )
V_71 = true ;
if ( V_71 ) {
enum V_75 V_76 ;
V_76 = V_68 -> V_74 ( V_68 , V_72 ) ;
if ( V_76 == V_77 ) {
V_69 |= ( 1 << V_68 -> V_62 . V_1 ) ;
}
}
}
if ( V_69 ) {
F_17 ( & V_15 -> V_38 ) ;
V_15 -> V_17 . V_78 |= V_69 ;
F_20 ( & V_15 -> V_38 ) ;
F_27 ( & V_15 -> V_17 . V_79 ) ;
}
}
static void F_28 ( struct V_50 * V_51 )
{
struct V_14 * V_15 =
F_14 ( V_51 , struct V_14 , V_17 . V_79 ) ;
struct V_28 * V_29 = & V_15 -> V_30 ;
struct V_31 * V_32 = & V_29 -> V_32 ;
struct V_33 * V_33 ;
struct V_34 * V_34 ;
struct V_35 * V_36 ;
bool V_80 = false ;
T_1 V_81 ;
F_29 ( & V_32 -> V_58 ) ;
F_5 ( L_8 ) ;
F_17 ( & V_15 -> V_38 ) ;
V_81 = V_15 -> V_17 . V_78 ;
V_15 -> V_17 . V_78 = 0 ;
F_6 ( V_15 ) ;
F_20 ( & V_15 -> V_38 ) ;
F_8 (connector, &mode_config->connector_list, head) {
V_33 = F_9 ( V_36 ) ;
if ( ! V_33 -> V_41 )
continue;
V_34 = V_33 -> V_41 ;
if ( V_81 & ( 1 << V_34 -> V_1 ) ) {
F_5 ( L_9 ,
V_36 -> V_43 , V_34 -> V_1 ) ;
if ( V_34 -> V_82 )
V_34 -> V_82 ( V_34 ) ;
if ( F_22 ( V_29 , V_36 ) )
V_80 = true ;
}
}
F_30 ( & V_32 -> V_58 ) ;
if ( V_80 )
F_31 ( V_29 ) ;
}
void F_32 ( struct V_14 * V_15 ,
T_1 V_83 , T_1 V_84 )
{
int V_52 ;
enum V_3 V_3 ;
bool V_85 = false ;
bool V_86 = false , V_87 = false ;
bool V_88 ;
if ( ! V_83 )
return;
F_33 ( & V_15 -> V_38 ) ;
F_18 (i) {
if ( ! ( F_34 ( V_52 ) & V_83 ) )
continue;
V_88 = F_1 ( V_52 , & V_3 ) &&
V_15 -> V_17 . V_73 [ V_3 ] ;
if ( V_88 ) {
bool V_72 = V_84 & F_34 ( V_52 ) ;
F_19 ( L_10 , F_35 ( V_3 ) ,
V_72 ? L_11 : L_12 ) ;
V_86 = true ;
if ( V_72 ) {
V_15 -> V_17 . V_65 |= ( 1 << V_3 ) ;
} else {
V_15 -> V_17 . V_66 |= ( 1 << V_3 ) ;
continue;
}
}
if ( V_15 -> V_17 . V_18 [ V_52 ] . V_26 == V_44 ) {
F_36 ( ! F_37 ( V_15 ) ,
L_13 , V_52 ) ;
continue;
}
if ( V_15 -> V_17 . V_18 [ V_52 ] . V_26 != V_53 )
continue;
if ( ! V_88 ) {
V_15 -> V_17 . V_78 |= F_34 ( V_52 ) ;
V_87 = true ;
}
if ( F_2 ( V_15 , V_52 ) ) {
V_15 -> V_17 . V_78 &= ~ F_34 ( V_52 ) ;
V_85 = true ;
}
}
if ( V_85 )
V_15 -> V_54 . V_55 ( V_15 ) ;
F_38 ( & V_15 -> V_38 ) ;
if ( V_86 )
F_39 ( V_15 -> V_17 . V_89 , & V_15 -> V_17 . V_64 ) ;
if ( V_87 )
F_27 ( & V_15 -> V_17 . V_79 ) ;
}
void F_40 ( struct V_14 * V_15 )
{
int V_52 ;
F_18 (i) {
V_15 -> V_17 . V_18 [ V_52 ] . V_24 = 0 ;
V_15 -> V_17 . V_18 [ V_52 ] . V_26 = V_53 ;
}
F_41 ( V_15 -> V_17 . V_90 , false ) ;
F_27 ( & V_15 -> V_17 . V_91 ) ;
F_17 ( & V_15 -> V_38 ) ;
if ( V_15 -> V_54 . V_55 )
V_15 -> V_54 . V_55 ( V_15 ) ;
F_20 ( & V_15 -> V_38 ) ;
}
void F_42 ( struct V_50 * V_51 ) {
struct V_14 * V_15 =
F_14 ( V_51 , struct V_14 ,
V_17 . V_91 ) ;
struct V_28 * V_29 = & V_15 -> V_30 ;
struct V_31 * V_32 = & V_29 -> V_32 ;
struct V_35 * V_36 ;
bool V_92 ;
F_29 ( & V_29 -> V_32 . V_58 ) ;
V_92 = F_43 ( V_15 -> V_17 . V_90 ) ;
F_8 (connector, &mode_config->connector_list, head) {
struct V_33 * V_33 =
F_9 ( V_36 ) ;
V_36 -> V_39 = V_33 -> V_39 ;
if ( V_33 -> V_93 )
continue;
if ( ! V_36 -> V_39 && F_44 ( V_29 ) &&
V_33 -> V_41 -> V_1 > V_42 ) {
V_36 -> V_39 = V_92 ?
V_45 |
V_46 :
V_40 ;
}
}
if ( V_92 )
F_11 ( V_29 ) ;
F_30 ( & V_29 -> V_32 . V_58 ) ;
if ( ! V_92 )
F_45 ( V_29 ) ;
}
void F_46 ( struct V_14 * V_15 )
{
F_41 ( V_15 -> V_17 . V_90 , true ) ;
F_27 ( & V_15 -> V_17 . V_91 ) ;
}
void F_47 ( struct V_14 * V_15 )
{
F_48 ( & V_15 -> V_17 . V_79 , F_28 ) ;
F_48 ( & V_15 -> V_17 . V_64 , F_26 ) ;
F_48 ( & V_15 -> V_17 . V_91 , F_42 ) ;
F_49 ( & V_15 -> V_17 . V_48 ,
F_13 ) ;
}
void F_50 ( struct V_14 * V_15 )
{
F_17 ( & V_15 -> V_38 ) ;
V_15 -> V_17 . V_65 = 0 ;
V_15 -> V_17 . V_66 = 0 ;
V_15 -> V_17 . V_78 = 0 ;
F_20 ( & V_15 -> V_38 ) ;
F_51 ( & V_15 -> V_17 . V_64 ) ;
F_51 ( & V_15 -> V_17 . V_79 ) ;
F_51 ( & V_15 -> V_17 . V_91 ) ;
F_52 ( & V_15 -> V_17 . V_48 ) ;
}
bool F_53 ( struct V_14 * V_15 , enum V_1 V_2 )
{
bool V_76 = false ;
if ( V_2 == V_42 )
return false ;
F_17 ( & V_15 -> V_38 ) ;
if ( V_15 -> V_17 . V_18 [ V_2 ] . V_26 == V_53 ) {
V_15 -> V_17 . V_18 [ V_2 ] . V_26 = V_44 ;
V_76 = true ;
}
F_20 ( & V_15 -> V_38 ) ;
return V_76 ;
}
void F_54 ( struct V_14 * V_15 , enum V_1 V_2 )
{
if ( V_2 == V_42 )
return;
F_17 ( & V_15 -> V_38 ) ;
V_15 -> V_17 . V_18 [ V_2 ] . V_26 = V_53 ;
F_20 ( & V_15 -> V_38 ) ;
}
