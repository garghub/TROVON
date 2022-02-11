static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
void F_3 ( struct V_2 * V_2 )
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
struct V_10 * V_12 )
{
struct V_2 * V_2 = F_24 ( V_39 -> V_41 ? V_39 -> V_41 : F_25 ( V_39 ) -> V_41 ) ;
const struct V_42 * V_43 ;
struct V_42 V_44 ;
T_1 V_45 ;
const struct V_46 * V_47 ;
struct V_46 V_48 ;
V_47 = F_26 ( V_39 , V_40 , sizeof( V_48 ) , & V_48 ) ;
if ( ! V_47 || V_47 -> V_49 != V_50 ) {
V_12 -> V_13 . V_18 . V_19 = 0 ;
V_12 -> V_16 . V_18 . V_19 = 0 ;
return true ;
}
V_43 = F_26 ( V_39 , V_40 , 8 , & V_44 ) ;
if ( ! V_43 )
return true ;
if ( F_27 ( V_47 -> V_51 ) != V_52 ) {
F_14 ( L_8 ) ;
return false ;
}
V_12 -> V_16 . V_18 . V_21 . V_20 = V_43 -> V_53 ;
V_45 = F_10 ( V_2 , V_12 ) ;
V_12 -> V_13 . V_18 . V_21 . V_20 = V_45 ;
return true ;
}
static int F_28 ( struct V_54 * V_55 ,
const struct V_10 * V_12 )
{
return F_29 ( V_55 , L_9 ,
F_27 ( V_12 -> V_13 . V_18 . V_21 . V_20 ) ,
F_27 ( V_12 -> V_16 . V_18 . V_21 . V_20 ) ) ;
}
static int F_30 ( struct V_54 * V_55 , struct V_22 * V_23 )
{
return F_29 ( V_55 , L_10 ,
( V_23 -> V_56 . V_21 . V_57 / V_58 ) ,
( V_23 -> V_56 . V_21 . V_59 / V_58 ) ) ;
}
static unsigned int * F_31 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_60 ;
}
static int F_32 ( struct V_22 * V_23 ,
const struct V_38 * V_39 ,
unsigned int V_40 ,
enum V_61 V_62 ,
T_2 V_63 ,
unsigned int V_64 ,
unsigned int * V_65 )
{
if ( V_23 -> V_66 & V_67 ) {
F_33 ( V_23 , V_62 , V_39 ,
V_23 -> V_56 . V_21 . V_59 ) ;
if ( ! F_34 ( V_68 , & V_23 -> V_66 ) )
F_35 ( V_69 , V_23 ) ;
} else
F_33 ( V_23 , V_62 , V_39 ,
V_23 -> V_56 . V_21 . V_57 ) ;
return V_70 ;
}
static bool F_36 ( struct V_22 * V_23 , const struct V_38 * V_39 ,
unsigned int V_40 , unsigned int * V_65 )
{
F_14 ( L_11 ) ;
F_15 ( & V_23 -> V_71 [ V_35 ] . V_12 ) ;
V_23 -> V_56 . V_21 . V_59 = V_65 [ V_72 ] ;
V_23 -> V_56 . V_21 . V_57 = V_65 [ V_73 ] ;
return true ;
}
static void F_37 ( struct V_22 * V_23 )
{
struct V_22 * V_74 = V_23 -> V_74 ;
F_14 ( L_12 ) ;
if ( ! V_74 )
F_14 ( L_13 ) ;
else
F_21 ( V_74 ) ;
}
static int F_38 ( struct V_75 * V_76 [] ,
struct V_2 * V_2 , void * V_77 )
{
unsigned int * V_65 = V_77 ;
struct V_1 * V_4 = F_1 ( V_2 ) ;
V_65 [ V_73 ] = V_4 -> V_60 [ V_73 ] ;
V_65 [ V_72 ] = V_4 -> V_60 [ V_72 ] ;
if ( V_76 [ V_78 ] ) {
V_65 [ V_73 ] =
F_39 ( F_40 ( V_76 [ V_78 ] ) ) * V_58 ;
}
if ( V_76 [ V_79 ] ) {
V_65 [ V_72 ] =
F_39 ( F_40 ( V_76 [ V_79 ] ) ) * V_58 ;
}
return 0 ;
}
static int
F_41 ( struct V_38 * V_39 , const void * V_77 )
{
const unsigned int * V_65 = V_77 ;
if ( F_42 ( V_39 , V_78 ,
F_43 ( V_65 [ V_73 ] / V_58 ) ) ||
F_42 ( V_39 , V_79 ,
F_43 ( V_65 [ V_72 ] / V_58 ) ) )
goto V_80;
return 0 ;
V_80:
return - V_81 ;
}
static int F_44 ( struct V_2 * V_2 , T_3 V_56 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
int V_82 ;
F_45 ( & V_4 -> V_8 ) ;
F_46 ( & V_4 -> V_34 ) ;
for ( V_82 = 0 ; V_82 < V_83 ; V_82 ++ )
V_4 -> V_60 [ V_82 ] = V_60 [ V_82 ] ;
return 0 ;
}
static int F_47 ( struct V_2 * V_2 )
{
int V_84 = 0 ;
V_84 = F_48 ( V_2 , & V_85 ) ;
if ( V_84 < 0 )
F_49 ( L_14 ) ;
return V_84 ;
}
static void F_50 ( struct V_2 * V_2 )
{
F_51 ( V_2 , & V_85 ) ;
F_3 ( V_2 ) ;
}
static int T_4 F_52 ( void )
{
int V_84 ;
V_84 = F_53 ( & V_86 ) ;
if ( V_84 < 0 )
goto V_87;
V_84 = F_54 ( & V_85 ) ;
if ( V_84 < 0 )
goto V_88;
return 0 ;
V_88:
F_55 ( & V_86 ) ;
V_87:
return V_84 ;
}
static void T_5 F_56 ( void )
{
F_57 ( & V_85 ) ;
F_55 ( & V_86 ) ;
}
