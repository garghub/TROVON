static inline int F_1 ( unsigned int V_1 ,
unsigned int V_2 ,
unsigned int V_3 )
{
return ( ( V_1 >= V_2 ) && ( V_1 <= V_3 ) ) ;
}
static struct V_4 * F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_4 * V_9 ;
if ( ! V_6 && ! F_3 ( & V_10 ) ) {
F_4 ( L_1
L_2 , V_11 ) ;
return F_5 ( V_10 . V_12 ,
struct V_4 , V_13 ) ;
}
V_8 = F_6 ( V_6 ) ;
if ( ! V_8 )
return NULL ;
F_7 (mfd, &sta2x11_mfd_list, list) {
if ( V_9 -> V_8 == V_8 )
return V_9 ;
}
return NULL ;
}
static int F_8 ( struct V_5 * V_6 , T_1 V_14 )
{
int V_15 ;
struct V_4 * V_9 = F_2 ( V_6 ) ;
struct V_7 * V_8 ;
if ( V_9 )
return - V_16 ;
V_8 = F_6 ( V_6 ) ;
if ( ! V_8 )
return - V_17 ;
V_9 = F_9 ( sizeof( * V_9 ) , V_14 ) ;
if ( ! V_9 )
return - V_18 ;
F_10 ( & V_9 -> V_13 ) ;
for ( V_15 = 0 ; V_15 < F_11 ( V_9 -> V_19 ) ; V_15 ++ )
F_12 ( & V_9 -> V_19 [ V_15 ] ) ;
V_9 -> V_8 = V_8 ;
F_13 ( & V_9 -> V_13 , & V_10 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_4 * V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return - V_20 ;
F_15 ( & V_9 -> V_13 ) ;
F_16 ( V_9 ) ;
return 0 ;
}
T_2 F_17 ( struct V_5 * V_6 , T_2 V_21 , T_2 V_22 , T_2 V_23 ,
enum V_24 V_25 )
{
struct V_4 * V_9 = F_2 ( V_6 ) ;
T_2 V_1 ;
unsigned long V_14 ;
void T_3 * V_26 ;
if ( ! V_9 ) {
F_18 ( & V_6 -> V_27 , L_3 ) ;
return 0 ;
}
V_26 = V_9 -> V_26 [ V_25 ] ;
if ( ! V_26 ) {
F_18 ( & V_6 -> V_27 , L_4 ) ;
return 0 ;
}
F_19 ( & V_9 -> V_19 [ V_25 ] , V_14 ) ;
V_1 = F_20 ( V_26 + V_21 ) ;
V_1 &= ~ V_22 ;
V_1 |= V_23 ;
if ( V_22 )
F_21 ( V_1 , V_26 + V_21 ) ;
F_22 ( & V_9 -> V_19 [ V_25 ] , V_14 ) ;
return V_1 ;
}
int F_23 ( struct V_28 * V_27 ,
enum V_24 V_25 ,
void T_3 * * V_26 ,
T_4 * * V_19 )
{
struct V_5 * V_6 = * (struct V_5 * * ) ( V_27 -> V_27 . V_29 ) ;
struct V_4 * V_9 ;
if ( ! V_6 )
return - V_20 ;
V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return - V_20 ;
if ( V_25 >= V_30 )
return - V_20 ;
* V_26 = V_9 -> V_26 [ V_25 ] ;
* V_19 = & V_9 -> V_19 [ V_25 ] ;
F_24 ( L_5 , V_11 , __LINE__ , * V_26 ) ;
return * V_26 ? 0 : - V_20 ;
}
static void F_25 ( void * V_31 )
{
T_4 * V_19 = V_31 ;
F_26 ( V_19 ) ;
}
static void F_27 ( void * V_31 )
{
T_4 * V_19 = V_31 ;
F_28 ( V_19 ) ;
}
static void F_29 ( void * V_31 )
{
}
static bool F_30 ( struct V_32 * V_27 , unsigned int V_21 )
{
return ! F_1 ( V_21 , V_33 , V_34 ) ;
}
static bool F_31 ( struct V_32 * V_27 , unsigned int V_21 )
{
return ( V_21 == V_35 ) ||
F_1 ( V_21 , V_36 , V_37 ) ;
}
static bool F_32 ( struct V_32 * V_27 , unsigned int V_21 )
{
return false ;
}
static bool F_33 ( struct V_32 * V_27 , unsigned int V_21 )
{
if ( V_21 >= V_38 )
V_21 -= V_38 ;
switch ( V_21 ) {
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
return true ;
default:
return false ;
}
}
static bool F_34 ( struct V_32 * V_27 , unsigned int V_21 )
{
if ( V_21 >= V_38 )
V_21 -= V_38 ;
if ( ! F_33 ( V_27 , V_21 ) )
return false ;
return V_21 != V_40 ;
}
static bool F_35 ( struct V_32 * V_27 ,
unsigned int V_21 )
{
return V_21 <= V_46 ||
F_1 ( V_21 , V_47 , V_48 ) ||
F_1 ( V_21 , V_49 ,
V_50 ) ||
V_21 == V_51 ||
F_1 ( V_21 , V_52 , V_53 ) ;
}
static bool F_36 ( struct V_32 * V_27 ,
unsigned int V_21 )
{
if ( ! F_35 ( V_27 , V_21 ) )
return false ;
switch ( V_21 ) {
case V_54 :
case V_50 :
case V_52 :
case V_55 ... V_46 :
case V_56 ... V_57 :
return false ;
default:
return true ;
}
}
static int F_37 ( struct V_28 * V_27 ,
enum V_24 V_25 )
{
struct V_5 * * V_6 ;
struct V_4 * V_9 ;
struct V_58 * V_59 ;
const char * V_60 = V_61 [ V_25 ] ;
struct V_62 * V_62 = V_63 [ V_25 ] ;
V_6 = V_27 -> V_27 . V_29 ;
V_9 = F_2 ( * V_6 ) ;
if ( ! V_9 )
return - V_20 ;
if ( ! V_62 )
return - V_20 ;
V_59 = F_38 ( V_27 , V_64 , 0 ) ;
if ( ! V_59 )
return - V_18 ;
if ( ! F_39 ( V_59 -> V_2 , F_40 ( V_59 ) , V_60 ) )
return - V_16 ;
V_9 -> V_26 [ V_25 ] = F_41 ( V_59 -> V_2 , F_40 ( V_59 ) ) ;
if ( ! V_9 -> V_26 [ V_25 ] ) {
F_42 ( V_59 -> V_2 , F_40 ( V_59 ) ) ;
return - V_18 ;
}
V_62 -> V_65 = & V_9 -> V_19 ;
V_62 -> V_66 = V_67 ;
V_9 -> V_68 [ V_25 ] = F_43 ( & V_27 -> V_27 , V_9 -> V_26 [ V_25 ] ,
V_62 ) ;
F_44 ( ! V_9 -> V_68 [ V_25 ] ) ;
return 0 ;
}
static int F_45 ( struct V_28 * V_27 )
{
return F_37 ( V_27 , V_69 ) ;
}
static int F_46 ( struct V_28 * V_27 )
{
return F_37 ( V_27 , V_70 ) ;
}
static int F_47 ( struct V_28 * V_27 )
{
return F_37 ( V_27 , V_71 ) ;
}
static int F_48 ( struct V_28 * V_27 )
{
return F_37 ( V_27 , V_72 ) ;
}
static int T_5 F_49 ( void )
{
F_50 ( L_6 , V_11 ) ;
return F_51 ( & V_73 ) ;
}
static int T_5 F_52 ( void )
{
F_50 ( L_6 , V_11 ) ;
return F_51 ( & V_74 ) ;
}
static int T_5 F_53 ( void )
{
F_50 ( L_6 , V_11 ) ;
return F_51 ( & V_75 ) ;
}
static int T_5 F_54 ( void )
{
F_50 ( L_6 , V_11 ) ;
return F_51 ( & V_76 ) ;
}
static int F_55 ( struct V_5 * V_6 , T_6 V_77 )
{
F_56 ( V_6 ) ;
F_57 ( V_6 ) ;
F_58 ( V_6 , F_59 ( V_6 , V_77 ) ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 )
{
int V_78 ;
F_58 ( V_6 , 0 ) ;
V_78 = F_61 ( V_6 ) ;
if ( V_78 )
return V_78 ;
F_62 ( V_6 ) ;
return 0 ;
}
static void F_63 ( struct V_5 * V_6 ,
struct V_79 * V_80 )
{
int V_15 , V_81 ;
for ( V_15 = 0 ; V_15 < F_11 ( V_80 -> V_82 ) ; V_15 ++ )
for ( V_81 = 0 ; V_81 < V_80 -> V_82 [ V_15 ] . V_83 ; V_81 ++ ) {
V_80 -> V_82 [ V_15 ] . V_84 [ V_81 ] . V_85 = sizeof( V_6 ) ;
V_80 -> V_82 [ V_15 ] . V_84 [ V_81 ] . V_29 = & V_6 ;
}
}
static int F_64 ( struct V_5 * V_6 ,
const struct V_86 * V_87 )
{
int V_78 , V_15 ;
struct V_79 * V_88 ;
F_65 ( & V_6 -> V_27 , L_6 , V_11 ) ;
V_78 = F_61 ( V_6 ) ;
if ( V_78 ) {
F_66 ( & V_6 -> V_27 , L_7 ) ;
return V_78 ;
}
V_78 = F_67 ( V_6 ) ;
if ( V_78 )
F_65 ( & V_6 -> V_27 , L_8 ) ;
V_88 = V_87 -> V_32 == V_89 ?
& V_90 [ V_91 ] :
& V_90 [ V_92 ] ;
F_63 ( V_6 , V_88 ) ;
if ( ! F_2 ( V_6 ) )
F_8 ( V_6 , V_93 ) ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ ) {
V_78 = F_68 ( & V_6 -> V_27 , - 1 ,
V_88 -> V_82 [ V_15 ] . V_84 ,
V_88 -> V_82 [ V_15 ] . V_83 ,
& V_6 -> V_58 [ V_15 ] ,
0 , NULL ) ;
if ( V_78 ) {
F_66 ( & V_6 -> V_27 ,
L_9 , V_15 , V_78 ) ;
goto V_94;
}
}
return 0 ;
V_94:
F_69 ( & V_6 -> V_27 ) ;
F_57 ( V_6 ) ;
F_70 ( V_6 ) ;
return V_78 ;
}
static int T_5 F_71 ( void )
{
F_50 ( L_6 , V_11 ) ;
return F_72 ( & V_95 ) ;
}
