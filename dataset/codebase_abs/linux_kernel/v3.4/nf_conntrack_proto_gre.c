void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_5 * V_6 , * V_7 ;
F_3 ( & V_3 -> V_8 ) ;
F_4 (km, tmp, &net_gre->keymap_list, list) {
F_5 ( & V_6 -> V_9 ) ;
F_6 ( V_6 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static inline int F_8 ( const struct V_5 * V_6 ,
const struct V_10 * V_11 )
{
return V_6 -> V_12 . V_13 . V_14 == V_11 -> V_13 . V_14 &&
! memcmp ( & V_6 -> V_12 . V_13 . V_15 , & V_11 -> V_13 . V_15 , sizeof( V_11 -> V_13 . V_15 ) ) &&
! memcmp ( & V_6 -> V_12 . V_16 . V_15 , & V_11 -> V_16 . V_15 , sizeof( V_11 -> V_16 . V_15 ) ) &&
V_6 -> V_12 . V_16 . V_17 == V_11 -> V_16 . V_17 &&
V_6 -> V_12 . V_16 . V_18 . V_19 == V_11 -> V_16 . V_18 . V_19 ;
}
static T_1 F_9 ( struct V_1 * V_1 , struct V_10 * V_11 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_5 * V_6 ;
T_1 V_20 = 0 ;
F_10 ( & V_3 -> V_8 ) ;
F_11 (km, &net_gre->keymap_list, list) {
if ( F_8 ( V_6 , V_11 ) ) {
V_20 = V_6 -> V_12 . V_13 . V_18 . V_21 . V_20 ;
break;
}
}
F_12 ( & V_3 -> V_8 ) ;
F_13 ( L_1 , V_20 ) ;
F_14 ( V_11 ) ;
return V_20 ;
}
int F_15 ( struct V_22 * V_23 , enum V_24 V_25 ,
struct V_10 * V_11 )
{
struct V_1 * V_1 = F_16 ( V_23 ) ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_26 * V_27 = F_17 ( V_23 ) ;
struct V_5 * * V_28 , * V_6 ;
V_28 = & V_27 -> V_27 . V_29 . V_30 [ V_25 ] ;
if ( * V_28 ) {
F_10 ( & V_3 -> V_8 ) ;
F_11 (km, &net_gre->keymap_list, list) {
if ( F_8 ( V_6 , V_11 ) && V_6 == * V_28 ) {
F_12 ( & V_3 -> V_8 ) ;
return 0 ;
}
}
F_12 ( & V_3 -> V_8 ) ;
F_13 ( L_2 ,
V_25 == V_31 ? L_3 : L_4 , V_23 ) ;
return - V_32 ;
}
V_6 = F_18 ( sizeof( * V_6 ) , V_33 ) ;
if ( ! V_6 )
return - V_34 ;
memcpy ( & V_6 -> V_12 , V_11 , sizeof( * V_11 ) ) ;
* V_28 = V_6 ;
F_13 ( L_5 , V_6 ) ;
F_14 ( & V_6 -> V_12 ) ;
F_3 ( & V_3 -> V_8 ) ;
F_19 ( & V_6 -> V_9 , & V_3 -> V_35 ) ;
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
void F_20 ( struct V_22 * V_23 )
{
struct V_1 * V_1 = F_16 ( V_23 ) ;
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
struct V_26 * V_27 = F_17 ( V_23 ) ;
enum V_24 V_25 ;
F_13 ( L_6 , V_23 ) ;
F_3 ( & V_3 -> V_8 ) ;
for ( V_25 = V_36 ; V_25 < V_37 ; V_25 ++ ) {
if ( V_27 -> V_27 . V_29 . V_30 [ V_25 ] ) {
F_13 ( L_7 ,
V_27 -> V_27 . V_29 . V_30 [ V_25 ] ) ;
F_5 ( & V_27 -> V_27 . V_29 . V_30 [ V_25 ] -> V_9 ) ;
F_6 ( V_27 -> V_27 . V_29 . V_30 [ V_25 ] ) ;
V_27 -> V_27 . V_29 . V_30 [ V_25 ] = NULL ;
}
}
F_7 ( & V_3 -> V_8 ) ;
}
static bool F_21 ( struct V_10 * V_12 ,
const struct V_10 * V_38 )
{
V_12 -> V_16 . V_18 . V_21 . V_20 = V_38 -> V_13 . V_18 . V_21 . V_20 ;
V_12 -> V_13 . V_18 . V_21 . V_20 = V_38 -> V_16 . V_18 . V_21 . V_20 ;
return true ;
}
static bool F_22 ( const struct V_39 * V_40 , unsigned int V_41 ,
struct V_10 * V_12 )
{
struct V_1 * V_1 = F_23 ( V_40 -> V_42 ? V_40 -> V_42 : F_24 ( V_40 ) -> V_42 ) ;
const struct V_43 * V_44 ;
struct V_43 V_45 ;
T_1 V_46 ;
const struct V_47 * V_48 ;
struct V_47 V_49 ;
V_48 = F_25 ( V_40 , V_41 , sizeof( V_49 ) , & V_49 ) ;
if ( ! V_48 || V_48 -> V_50 != V_51 ) {
V_12 -> V_13 . V_18 . V_19 = 0 ;
V_12 -> V_16 . V_18 . V_19 = 0 ;
return true ;
}
V_44 = F_25 ( V_40 , V_41 , 8 , & V_45 ) ;
if ( ! V_44 )
return true ;
if ( F_26 ( V_48 -> V_52 ) != V_53 ) {
F_13 ( L_8 ) ;
return false ;
}
V_12 -> V_16 . V_18 . V_21 . V_20 = V_44 -> V_54 ;
V_46 = F_9 ( V_1 , V_12 ) ;
V_12 -> V_13 . V_18 . V_21 . V_20 = V_46 ;
return true ;
}
static int F_27 ( struct V_55 * V_56 ,
const struct V_10 * V_12 )
{
return F_28 ( V_56 , L_9 ,
F_26 ( V_12 -> V_13 . V_18 . V_21 . V_20 ) ,
F_26 ( V_12 -> V_16 . V_18 . V_21 . V_20 ) ) ;
}
static int F_29 ( struct V_55 * V_56 , struct V_22 * V_23 )
{
return F_28 ( V_56 , L_10 ,
( V_23 -> V_57 . V_21 . V_58 / V_59 ) ,
( V_23 -> V_57 . V_21 . V_60 / V_59 ) ) ;
}
static unsigned int * F_30 ( struct V_1 * V_1 )
{
return V_61 ;
}
static int F_31 ( struct V_22 * V_23 ,
const struct V_39 * V_40 ,
unsigned int V_41 ,
enum V_62 V_63 ,
T_2 V_64 ,
unsigned int V_65 ,
unsigned int * V_66 )
{
if ( V_23 -> V_67 & V_68 ) {
F_32 ( V_23 , V_63 , V_40 ,
V_23 -> V_57 . V_21 . V_60 ) ;
if ( ! F_33 ( V_69 , & V_23 -> V_67 ) )
F_34 ( V_70 , V_23 ) ;
} else
F_32 ( V_23 , V_63 , V_40 ,
V_23 -> V_57 . V_21 . V_58 ) ;
return V_71 ;
}
static bool F_35 ( struct V_22 * V_23 , const struct V_39 * V_40 ,
unsigned int V_41 , unsigned int * V_66 )
{
F_13 ( L_11 ) ;
F_14 ( & V_23 -> V_72 [ V_36 ] . V_12 ) ;
V_23 -> V_57 . V_21 . V_60 = V_66 [ V_73 ] ;
V_23 -> V_57 . V_21 . V_58 = V_66 [ V_74 ] ;
return true ;
}
static void F_36 ( struct V_22 * V_23 )
{
struct V_22 * V_75 = V_23 -> V_75 ;
F_13 ( L_12 ) ;
if ( ! V_75 )
F_13 ( L_13 ) ;
else
F_20 ( V_75 ) ;
}
static int F_37 ( struct V_76 * V_77 [] , void * V_78 )
{
unsigned int * V_66 = V_78 ;
V_66 [ V_74 ] = V_61 [ V_74 ] ;
V_66 [ V_73 ] = V_61 [ V_73 ] ;
if ( V_77 [ V_79 ] ) {
V_66 [ V_74 ] =
F_38 ( F_39 ( V_77 [ V_79 ] ) ) * V_59 ;
}
if ( V_77 [ V_80 ] ) {
V_66 [ V_73 ] =
F_38 ( F_39 ( V_77 [ V_80 ] ) ) * V_59 ;
}
return 0 ;
}
static int
F_40 ( struct V_39 * V_40 , const void * V_78 )
{
const unsigned int * V_66 = V_78 ;
F_41 ( V_40 , V_79 ,
F_42 ( V_66 [ V_74 ] / V_59 ) ) ;
F_41 ( V_40 , V_80 ,
F_42 ( V_66 [ V_73 ] / V_59 ) ) ;
return 0 ;
V_81:
return - V_82 ;
}
static int F_43 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_44 ( & V_3 -> V_8 ) ;
F_45 ( & V_3 -> V_35 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_1 )
{
F_1 ( V_1 ) ;
}
static int T_3 F_47 ( void )
{
int V_83 ;
V_83 = F_48 ( & V_84 ) ;
if ( V_83 < 0 )
return V_83 ;
V_83 = F_49 ( & V_85 ) ;
if ( V_83 < 0 )
F_50 ( & V_84 ) ;
return V_83 ;
}
static void T_4 F_51 ( void )
{
F_50 ( & V_84 ) ;
F_52 ( & V_85 ) ;
}
