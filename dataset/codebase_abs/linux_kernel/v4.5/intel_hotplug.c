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
struct V_28 * V_29 = V_15 -> V_29 ;
struct V_30 * V_31 = & V_29 -> V_31 ;
struct V_32 * V_32 ;
struct V_33 * V_33 ;
struct V_34 * V_35 ;
enum V_1 V_2 ;
bool V_36 = false ;
F_7 ( & V_15 -> V_37 ) ;
F_8 (connector, &mode_config->connector_list, head) {
if ( V_35 -> V_38 != V_39 )
continue;
V_32 = F_9 ( V_35 ) ;
V_33 = V_32 -> V_40 ;
if ( ! V_33 )
continue;
V_2 = V_33 -> V_1 ;
if ( V_2 == V_41 ||
V_15 -> V_17 . V_18 [ V_2 ] . V_26 != V_27 )
continue;
F_10 ( L_4
L_5 ,
V_35 -> V_42 ) ;
V_15 -> V_17 . V_18 [ V_2 ] . V_26 = V_43 ;
V_35 -> V_38 = V_44
| V_45 ;
V_36 = true ;
}
if ( V_36 ) {
F_11 ( V_29 ) ;
F_12 ( V_46 , & V_15 -> V_17 . V_47 ,
F_3 ( V_48 ) ) ;
}
}
static void F_13 ( struct V_49 * V_50 )
{
struct V_14 * V_15 =
F_14 ( V_50 , F_15 ( * V_15 ) ,
V_17 . V_47 . V_50 ) ;
struct V_28 * V_29 = V_15 -> V_29 ;
struct V_30 * V_31 = & V_29 -> V_31 ;
int V_51 ;
F_16 ( V_15 ) ;
F_17 ( & V_15 -> V_37 ) ;
F_18 (i) {
struct V_34 * V_35 ;
if ( V_15 -> V_17 . V_18 [ V_51 ] . V_26 != V_43 )
continue;
V_15 -> V_17 . V_18 [ V_51 ] . V_26 = V_52 ;
F_8 (connector, &mode_config->connector_list, head) {
struct V_32 * V_32 = F_9 ( V_35 ) ;
if ( V_32 -> V_40 -> V_1 == V_51 ) {
if ( V_35 -> V_38 != V_32 -> V_38 )
F_19 ( L_6 ,
V_35 -> V_42 ) ;
V_35 -> V_38 = V_32 -> V_38 ;
if ( ! V_35 -> V_38 )
V_35 -> V_38 = V_39 ;
}
}
}
if ( V_15 -> V_53 . V_54 )
V_15 -> V_53 . V_54 ( V_29 ) ;
F_20 ( & V_15 -> V_37 ) ;
F_21 ( V_15 ) ;
}
static bool F_22 ( struct V_28 * V_29 ,
struct V_34 * V_35 )
{
enum V_55 V_56 ;
F_23 ( ! F_24 ( & V_29 -> V_31 . V_57 ) ) ;
V_56 = V_35 -> V_58 ;
V_35 -> V_58 = V_35 -> V_59 -> V_60 ( V_35 , false ) ;
if ( V_56 == V_35 -> V_58 )
return false ;
F_5 ( L_7 ,
V_35 -> V_61 . V_62 ,
V_35 -> V_42 ,
F_25 ( V_56 ) ,
F_25 ( V_35 -> V_58 ) ) ;
return true ;
}
static void F_26 ( struct V_49 * V_50 )
{
struct V_14 * V_15 =
F_14 ( V_50 , struct V_14 , V_17 . V_63 ) ;
T_1 V_64 , V_65 ;
struct V_66 * V_67 ;
int V_51 ;
T_1 V_68 = 0 ;
F_17 ( & V_15 -> V_37 ) ;
V_64 = V_15 -> V_17 . V_64 ;
V_15 -> V_17 . V_64 = 0 ;
V_65 = V_15 -> V_17 . V_65 ;
V_15 -> V_17 . V_65 = 0 ;
F_20 ( & V_15 -> V_37 ) ;
for ( V_51 = 0 ; V_51 < V_69 ; V_51 ++ ) {
bool V_70 = false ;
bool V_71 = false ;
V_67 = V_15 -> V_17 . V_72 [ V_51 ] ;
if ( ! V_67 || ! V_67 -> V_73 )
continue;
if ( V_64 & ( 1 << V_51 ) ) {
V_70 = true ;
V_71 = true ;
} else if ( V_65 & ( 1 << V_51 ) )
V_70 = true ;
if ( V_70 ) {
enum V_74 V_75 ;
V_75 = V_67 -> V_73 ( V_67 , V_71 ) ;
if ( V_75 == V_76 ) {
V_68 |= ( 1 << V_67 -> V_61 . V_1 ) ;
}
}
}
if ( V_68 ) {
F_17 ( & V_15 -> V_37 ) ;
V_15 -> V_17 . V_77 |= V_68 ;
F_20 ( & V_15 -> V_37 ) ;
F_27 ( & V_15 -> V_17 . V_78 ) ;
}
}
static void F_28 ( struct V_49 * V_50 )
{
struct V_14 * V_15 =
F_14 ( V_50 , struct V_14 , V_17 . V_78 ) ;
struct V_28 * V_29 = V_15 -> V_29 ;
struct V_30 * V_31 = & V_29 -> V_31 ;
struct V_32 * V_32 ;
struct V_33 * V_33 ;
struct V_34 * V_35 ;
bool V_79 = false ;
T_1 V_80 ;
F_29 ( & V_31 -> V_57 ) ;
F_5 ( L_8 ) ;
F_17 ( & V_15 -> V_37 ) ;
V_80 = V_15 -> V_17 . V_77 ;
V_15 -> V_17 . V_77 = 0 ;
F_6 ( V_15 ) ;
F_20 ( & V_15 -> V_37 ) ;
F_8 (connector, &mode_config->connector_list, head) {
V_32 = F_9 ( V_35 ) ;
if ( ! V_32 -> V_40 )
continue;
V_33 = V_32 -> V_40 ;
if ( V_80 & ( 1 << V_33 -> V_1 ) ) {
F_5 ( L_9 ,
V_35 -> V_42 , V_33 -> V_1 ) ;
if ( V_33 -> V_81 )
V_33 -> V_81 ( V_33 ) ;
if ( F_22 ( V_29 , V_35 ) )
V_79 = true ;
}
}
F_30 ( & V_31 -> V_57 ) ;
if ( V_79 )
F_31 ( V_29 ) ;
}
void F_32 ( struct V_28 * V_29 ,
T_1 V_82 , T_1 V_83 )
{
struct V_14 * V_15 = V_29 -> V_84 ;
int V_51 ;
enum V_3 V_3 ;
bool V_85 = false ;
bool V_86 = false , V_87 = false ;
bool V_88 ;
if ( ! V_82 )
return;
F_33 ( & V_15 -> V_37 ) ;
F_18 (i) {
if ( ! ( F_34 ( V_51 ) & V_82 ) )
continue;
V_88 = F_1 ( V_51 , & V_3 ) &&
V_15 -> V_17 . V_72 [ V_3 ] ;
if ( V_88 ) {
bool V_71 = V_83 & F_34 ( V_51 ) ;
F_19 ( L_10 , F_35 ( V_3 ) ,
V_71 ? L_11 : L_12 ) ;
V_86 = true ;
if ( V_71 ) {
V_15 -> V_17 . V_64 |= ( 1 << V_3 ) ;
} else {
V_15 -> V_17 . V_65 |= ( 1 << V_3 ) ;
continue;
}
}
if ( V_15 -> V_17 . V_18 [ V_51 ] . V_26 == V_43 ) {
F_36 ( ! F_37 ( V_29 ) ,
L_13 , V_51 ) ;
continue;
}
if ( V_15 -> V_17 . V_18 [ V_51 ] . V_26 != V_52 )
continue;
if ( ! V_88 ) {
V_15 -> V_17 . V_77 |= F_34 ( V_51 ) ;
V_87 = true ;
}
if ( F_2 ( V_15 , V_51 ) ) {
V_15 -> V_17 . V_77 &= ~ F_34 ( V_51 ) ;
V_85 = true ;
}
}
if ( V_85 )
V_15 -> V_53 . V_54 ( V_29 ) ;
F_38 ( & V_15 -> V_37 ) ;
if ( V_86 )
F_39 ( V_15 -> V_17 . V_89 , & V_15 -> V_17 . V_63 ) ;
if ( V_87 )
F_27 ( & V_15 -> V_17 . V_78 ) ;
}
void F_40 ( struct V_14 * V_15 )
{
struct V_28 * V_29 = V_15 -> V_29 ;
struct V_30 * V_31 = & V_29 -> V_31 ;
struct V_34 * V_35 ;
int V_51 ;
F_18 (i) {
V_15 -> V_17 . V_18 [ V_51 ] . V_24 = 0 ;
V_15 -> V_17 . V_18 [ V_51 ] . V_26 = V_52 ;
}
F_8 (connector, &mode_config->connector_list, head) {
struct V_32 * V_32 = F_9 ( V_35 ) ;
V_35 -> V_38 = V_32 -> V_38 ;
if ( V_32 -> V_90 )
continue;
if ( ! V_35 -> V_38 && F_41 ( V_29 ) &&
V_32 -> V_40 -> V_1 > V_41 )
V_35 -> V_38 = V_39 ;
}
F_17 ( & V_15 -> V_37 ) ;
if ( V_15 -> V_53 . V_54 )
V_15 -> V_53 . V_54 ( V_29 ) ;
F_20 ( & V_15 -> V_37 ) ;
}
void F_42 ( struct V_14 * V_15 )
{
F_43 ( & V_15 -> V_17 . V_78 , F_28 ) ;
F_43 ( & V_15 -> V_17 . V_63 , F_26 ) ;
F_44 ( & V_15 -> V_17 . V_47 ,
F_13 ) ;
}
void F_45 ( struct V_14 * V_15 )
{
F_17 ( & V_15 -> V_37 ) ;
V_15 -> V_17 . V_64 = 0 ;
V_15 -> V_17 . V_65 = 0 ;
V_15 -> V_17 . V_77 = 0 ;
F_20 ( & V_15 -> V_37 ) ;
F_46 ( & V_15 -> V_17 . V_63 ) ;
F_46 ( & V_15 -> V_17 . V_78 ) ;
F_47 ( & V_15 -> V_17 . V_47 ) ;
}
