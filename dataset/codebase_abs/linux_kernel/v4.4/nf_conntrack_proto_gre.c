static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_5 * V_6 , * V_7 ;
F_4 ( & V_4 -> V_8 ) ;
F_5 (km, tmp, &net_gre->keymap_list, list) {
F_6 ( & V_6 -> V_9 ) ;
F_7 ( V_6 ) ;
}
F_8 ( & V_4 -> V_8 ) ;
}
static inline int F_9 ( const struct V_5 * V_6 ,
const struct V_10 * V_11 )
{
return V_6 -> V_12 . V_13 . V_14 == V_11 -> V_13 . V_14 &&
! memcmp ( & V_6 -> V_12 . V_13 . V_15 , & V_11 -> V_13 . V_15 , sizeof( V_11 -> V_13 . V_15 ) ) &&
! memcmp ( & V_6 -> V_12 . V_16 . V_15 , & V_11 -> V_16 . V_15 , sizeof( V_11 -> V_16 . V_15 ) ) &&
V_6 -> V_12 . V_16 . V_17 == V_11 -> V_16 . V_17 &&
V_6 -> V_12 . V_16 . V_18 . V_19 == V_11 -> V_16 . V_18 . V_19 ;
}
static T_1 F_10 ( struct V_2 * V_2 , struct V_10 * V_11 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_5 * V_6 ;
T_1 V_20 = 0 ;
F_11 ( & V_4 -> V_8 ) ;
F_12 (km, &net_gre->keymap_list, list) {
if ( F_9 ( V_6 , V_11 ) ) {
V_20 = V_6 -> V_12 . V_13 . V_18 . V_21 . V_20 ;
break;
}
}
F_13 ( & V_4 -> V_8 ) ;
F_14 ( L_1 , V_20 ) ;
F_15 ( V_11 ) ;
return V_20 ;
}
int F_16 ( struct V_22 * V_23 , enum V_24 V_25 ,
struct V_10 * V_11 )
{
struct V_2 * V_2 = F_17 ( V_23 ) ;
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_26 * V_27 = F_18 ( V_23 ) ;
struct V_5 * * V_28 , * V_6 ;
V_28 = & V_27 -> V_29 [ V_25 ] ;
if ( * V_28 ) {
F_11 ( & V_4 -> V_8 ) ;
F_12 (km, &net_gre->keymap_list, list) {
if ( F_9 ( V_6 , V_11 ) && V_6 == * V_28 ) {
F_13 ( & V_4 -> V_8 ) ;
return 0 ;
}
}
F_13 ( & V_4 -> V_8 ) ;
F_14 ( L_2 ,
V_25 == V_30 ? L_3 : L_4 , V_23 ) ;
return - V_31 ;
}
V_6 = F_19 ( sizeof( * V_6 ) , V_32 ) ;
if ( ! V_6 )
return - V_33 ;
memcpy ( & V_6 -> V_12 , V_11 , sizeof( * V_11 ) ) ;
* V_28 = V_6 ;
F_14 ( L_5 , V_6 ) ;
F_15 ( & V_6 -> V_12 ) ;
F_4 ( & V_4 -> V_8 ) ;
F_20 ( & V_6 -> V_9 , & V_4 -> V_34 ) ;
F_8 ( & V_4 -> V_8 ) ;
return 0 ;
}
void F_21 ( struct V_22 * V_23 )
{
struct V_2 * V_2 = F_17 ( V_23 ) ;
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_26 * V_27 = F_18 ( V_23 ) ;
enum V_24 V_25 ;
F_14 ( L_6 , V_23 ) ;
F_4 ( & V_4 -> V_8 ) ;
for ( V_25 = V_35 ; V_25 < V_36 ; V_25 ++ ) {
if ( V_27 -> V_29 [ V_25 ] ) {
F_14 ( L_7 ,
V_27 -> V_29 [ V_25 ] ) ;
F_6 ( & V_27 -> V_29 [ V_25 ] -> V_9 ) ;
F_7 ( V_27 -> V_29 [ V_25 ] ) ;
V_27 -> V_29 [ V_25 ] = NULL ;
}
}
F_8 ( & V_4 -> V_8 ) ;
}
static bool F_22 ( struct V_10 * V_12 ,
const struct V_10 * V_37 )
{
V_12 -> V_16 . V_18 . V_21 . V_20 = V_37 -> V_13 . V_18 . V_21 . V_20 ;
V_12 -> V_13 . V_18 . V_21 . V_20 = V_37 -> V_16 . V_18 . V_21 . V_20 ;
return true ;
}
static bool F_23 ( const struct V_38 * V_39 , unsigned int V_40 ,
struct V_2 * V_2 , struct V_10 * V_12 )
{
const struct V_41 * V_42 ;
struct V_41 V_43 ;
T_1 V_44 ;
const struct V_45 * V_46 ;
struct V_45 V_47 ;
V_46 = F_24 ( V_39 , V_40 , sizeof( V_47 ) , & V_47 ) ;
if ( ! V_46 || V_46 -> V_48 != V_49 ) {
V_12 -> V_13 . V_18 . V_19 = 0 ;
V_12 -> V_16 . V_18 . V_19 = 0 ;
return true ;
}
V_42 = F_24 ( V_39 , V_40 , 8 , & V_43 ) ;
if ( ! V_42 )
return true ;
if ( F_25 ( V_46 -> V_50 ) != V_51 ) {
F_14 ( L_8 ) ;
return false ;
}
V_12 -> V_16 . V_18 . V_21 . V_20 = V_42 -> V_52 ;
V_44 = F_10 ( V_2 , V_12 ) ;
V_12 -> V_13 . V_18 . V_21 . V_20 = V_44 ;
return true ;
}
static void F_26 ( struct V_53 * V_54 ,
const struct V_10 * V_12 )
{
F_27 ( V_54 , L_9 ,
F_25 ( V_12 -> V_13 . V_18 . V_21 . V_20 ) ,
F_25 ( V_12 -> V_16 . V_18 . V_21 . V_20 ) ) ;
}
static void F_28 ( struct V_53 * V_54 , struct V_22 * V_23 )
{
F_27 ( V_54 , L_10 ,
( V_23 -> V_55 . V_21 . V_56 / V_57 ) ,
( V_23 -> V_55 . V_21 . V_58 / V_57 ) ) ;
}
static unsigned int * F_29 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_59 ;
}
static int F_30 ( struct V_22 * V_23 ,
const struct V_38 * V_39 ,
unsigned int V_40 ,
enum V_60 V_61 ,
T_2 V_62 ,
unsigned int V_63 ,
unsigned int * V_64 )
{
if ( V_23 -> V_65 & V_66 ) {
F_31 ( V_23 , V_61 , V_39 ,
V_23 -> V_55 . V_21 . V_58 ) ;
if ( ! F_32 ( V_67 , & V_23 -> V_65 ) )
F_33 ( V_68 , V_23 ) ;
} else
F_31 ( V_23 , V_61 , V_39 ,
V_23 -> V_55 . V_21 . V_56 ) ;
return V_69 ;
}
static bool F_34 ( struct V_22 * V_23 , const struct V_38 * V_39 ,
unsigned int V_40 , unsigned int * V_64 )
{
F_14 ( L_11 ) ;
F_15 ( & V_23 -> V_70 [ V_35 ] . V_12 ) ;
V_23 -> V_55 . V_21 . V_58 = V_64 [ V_71 ] ;
V_23 -> V_55 . V_21 . V_56 = V_64 [ V_72 ] ;
return true ;
}
static void F_35 ( struct V_22 * V_23 )
{
struct V_22 * V_73 = V_23 -> V_73 ;
F_14 ( L_12 ) ;
if ( ! V_73 )
F_14 ( L_13 ) ;
else
F_21 ( V_73 ) ;
}
static int F_36 ( struct V_74 * V_75 [] ,
struct V_2 * V_2 , void * V_76 )
{
unsigned int * V_64 = V_76 ;
struct V_1 * V_4 = F_1 ( V_2 ) ;
V_64 [ V_72 ] = V_4 -> V_59 [ V_72 ] ;
V_64 [ V_71 ] = V_4 -> V_59 [ V_71 ] ;
if ( V_75 [ V_77 ] ) {
V_64 [ V_72 ] =
F_37 ( F_38 ( V_75 [ V_77 ] ) ) * V_57 ;
}
if ( V_75 [ V_78 ] ) {
V_64 [ V_71 ] =
F_37 ( F_38 ( V_75 [ V_78 ] ) ) * V_57 ;
}
return 0 ;
}
static int
F_39 ( struct V_38 * V_39 , const void * V_76 )
{
const unsigned int * V_64 = V_76 ;
if ( F_40 ( V_39 , V_77 ,
F_41 ( V_64 [ V_72 ] / V_57 ) ) ||
F_40 ( V_39 , V_78 ,
F_41 ( V_64 [ V_71 ] / V_57 ) ) )
goto V_79;
return 0 ;
V_79:
return - V_80 ;
}
static int F_42 ( struct V_2 * V_2 , T_3 V_55 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
int V_81 ;
F_43 ( & V_4 -> V_8 ) ;
F_44 ( & V_4 -> V_34 ) ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ )
V_4 -> V_59 [ V_81 ] = V_59 [ V_81 ] ;
return 0 ;
}
static int F_45 ( struct V_2 * V_2 )
{
int V_83 = 0 ;
V_83 = F_46 ( V_2 , & V_84 ) ;
if ( V_83 < 0 )
F_47 ( L_14 ) ;
return V_83 ;
}
static void F_48 ( struct V_2 * V_2 )
{
F_49 ( V_2 , & V_84 ) ;
F_3 ( V_2 ) ;
}
static int T_4 F_50 ( void )
{
int V_83 ;
V_83 = F_51 ( & V_85 ) ;
if ( V_83 < 0 )
goto V_86;
V_83 = F_52 ( & V_84 ) ;
if ( V_83 < 0 )
goto V_87;
return 0 ;
V_87:
F_53 ( & V_85 ) ;
V_86:
return V_83 ;
}
static void T_5 F_54 ( void )
{
F_55 ( & V_84 ) ;
F_53 ( & V_85 ) ;
}
