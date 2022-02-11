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
static int F_30 ( struct V_22 * V_23 ,
const struct V_39 * V_40 ,
unsigned int V_41 ,
enum V_61 V_62 ,
T_2 V_63 ,
unsigned int V_64 )
{
if ( V_23 -> V_65 & V_66 ) {
F_31 ( V_23 , V_62 , V_40 ,
V_23 -> V_57 . V_21 . V_60 ) ;
if ( ! F_32 ( V_67 , & V_23 -> V_65 ) )
F_33 ( V_68 , V_23 ) ;
} else
F_31 ( V_23 , V_62 , V_40 ,
V_23 -> V_57 . V_21 . V_58 ) ;
return V_69 ;
}
static bool F_34 ( struct V_22 * V_23 , const struct V_39 * V_40 ,
unsigned int V_41 )
{
F_13 ( L_11 ) ;
F_14 ( & V_23 -> V_70 [ V_36 ] . V_12 ) ;
V_23 -> V_57 . V_21 . V_60 = V_71 ;
V_23 -> V_57 . V_21 . V_58 = V_72 ;
return true ;
}
static void F_35 ( struct V_22 * V_23 )
{
struct V_22 * V_73 = V_23 -> V_73 ;
F_13 ( L_12 ) ;
if ( ! V_73 )
F_13 ( L_13 ) ;
else
F_20 ( V_73 ) ;
}
static int F_36 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , V_4 ) ;
F_37 ( & V_3 -> V_8 ) ;
F_38 ( & V_3 -> V_35 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_1 )
{
F_1 ( V_1 ) ;
}
static int T_3 F_40 ( void )
{
int V_74 ;
V_74 = F_41 ( & V_75 ) ;
if ( V_74 < 0 )
return V_74 ;
V_74 = F_42 ( & V_76 ) ;
if ( V_74 < 0 )
F_43 ( & V_75 ) ;
return V_74 ;
}
static void T_4 F_44 ( void )
{
F_43 ( & V_75 ) ;
F_45 ( & V_76 ) ;
}
