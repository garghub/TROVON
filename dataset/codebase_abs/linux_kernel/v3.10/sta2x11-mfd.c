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
T_2 F_14 ( struct V_5 * V_6 , T_2 V_20 , T_2 V_21 , T_2 V_22 ,
enum V_23 V_24 )
{
struct V_4 * V_9 = F_2 ( V_6 ) ;
T_2 V_1 ;
unsigned long V_14 ;
void T_3 * V_25 ;
if ( ! V_9 ) {
F_15 ( & V_6 -> V_26 , L_3 ) ;
return 0 ;
}
V_25 = V_9 -> V_25 [ V_24 ] ;
if ( ! V_25 ) {
F_15 ( & V_6 -> V_26 , L_4 ) ;
return 0 ;
}
F_16 ( & V_9 -> V_19 [ V_24 ] , V_14 ) ;
V_1 = F_17 ( V_25 + V_20 ) ;
V_1 &= ~ V_21 ;
V_1 |= V_22 ;
if ( V_21 )
F_18 ( V_1 , V_25 + V_20 ) ;
F_19 ( & V_9 -> V_19 [ V_24 ] , V_14 ) ;
return V_1 ;
}
int F_20 ( struct V_27 * V_26 ,
enum V_23 V_24 ,
void T_3 * * V_25 ,
T_4 * * V_19 )
{
struct V_5 * V_6 = * (struct V_5 * * ) ( V_26 -> V_26 . V_28 ) ;
struct V_4 * V_9 ;
if ( ! V_6 )
return - V_29 ;
V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return - V_29 ;
if ( V_24 >= V_30 )
return - V_29 ;
* V_25 = V_9 -> V_25 [ V_24 ] ;
* V_19 = & V_9 -> V_19 [ V_24 ] ;
F_21 ( L_5 , V_11 , __LINE__ , * V_25 ) ;
return * V_25 ? 0 : - V_29 ;
}
static void F_22 ( void * V_31 )
{
T_4 * V_19 = V_31 ;
F_23 ( V_19 ) ;
}
static void F_24 ( void * V_31 )
{
T_4 * V_19 = V_31 ;
F_25 ( V_19 ) ;
}
static void F_26 ( void * V_31 )
{
}
static bool F_27 ( struct V_32 * V_26 , unsigned int V_20 )
{
return ! F_1 ( V_20 , V_33 , V_34 ) ;
}
static bool F_28 ( struct V_32 * V_26 , unsigned int V_20 )
{
return ( V_20 == V_35 ) ||
F_1 ( V_20 , V_36 , V_37 ) ;
}
static bool F_29 ( struct V_32 * V_26 , unsigned int V_20 )
{
return false ;
}
static bool F_30 ( struct V_32 * V_26 , unsigned int V_20 )
{
if ( V_20 >= V_38 )
V_20 -= V_38 ;
switch ( V_20 ) {
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
static bool F_31 ( struct V_32 * V_26 , unsigned int V_20 )
{
if ( V_20 >= V_38 )
V_20 -= V_38 ;
if ( ! F_30 ( V_26 , V_20 ) )
return false ;
return V_20 != V_40 ;
}
static bool F_32 ( struct V_32 * V_26 ,
unsigned int V_20 )
{
return V_20 <= V_46 ||
F_1 ( V_20 , V_47 , V_48 ) ||
F_1 ( V_20 , V_49 ,
V_50 ) ||
V_20 == V_51 ||
F_1 ( V_20 , V_52 , V_53 ) ;
}
static bool F_33 ( struct V_32 * V_26 ,
unsigned int V_20 )
{
if ( ! F_32 ( V_26 , V_20 ) )
return false ;
switch ( V_20 ) {
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
static int F_34 ( struct V_27 * V_26 ,
enum V_23 V_24 )
{
struct V_5 * * V_6 ;
struct V_4 * V_9 ;
struct V_58 * V_59 ;
const char * V_60 = V_61 [ V_24 ] ;
struct V_62 * V_62 = V_63 [ V_24 ] ;
V_6 = V_26 -> V_26 . V_28 ;
V_9 = F_2 ( * V_6 ) ;
if ( ! V_9 )
return - V_29 ;
if ( ! V_62 )
return - V_29 ;
V_59 = F_35 ( V_26 , V_64 , 0 ) ;
if ( ! V_59 )
return - V_18 ;
if ( ! F_36 ( V_59 -> V_2 , F_37 ( V_59 ) , V_60 ) )
return - V_16 ;
V_9 -> V_25 [ V_24 ] = F_38 ( V_59 -> V_2 , F_37 ( V_59 ) ) ;
if ( ! V_9 -> V_25 [ V_24 ] ) {
F_39 ( V_59 -> V_2 , F_37 ( V_59 ) ) ;
return - V_18 ;
}
V_62 -> V_65 = & V_9 -> V_19 ;
V_62 -> V_66 = V_67 ;
V_9 -> V_68 [ V_24 ] = F_40 ( & V_26 -> V_26 , V_9 -> V_25 [ V_24 ] ,
V_62 ) ;
F_41 ( ! V_9 -> V_68 [ V_24 ] ) ;
return 0 ;
}
static int F_42 ( struct V_27 * V_26 )
{
return F_34 ( V_26 , V_69 ) ;
}
static int F_43 ( struct V_27 * V_26 )
{
return F_34 ( V_26 , V_70 ) ;
}
static int F_44 ( struct V_27 * V_26 )
{
return F_34 ( V_26 , V_71 ) ;
}
static int F_45 ( struct V_27 * V_26 )
{
return F_34 ( V_26 , V_72 ) ;
}
static int T_5 F_46 ( void )
{
F_47 ( L_6 , V_11 ) ;
return F_48 ( & V_73 ) ;
}
static int T_5 F_49 ( void )
{
F_47 ( L_6 , V_11 ) ;
return F_48 ( & V_74 ) ;
}
static int T_5 F_50 ( void )
{
F_47 ( L_6 , V_11 ) ;
return F_48 ( & V_75 ) ;
}
static int T_5 F_51 ( void )
{
F_47 ( L_6 , V_11 ) ;
return F_48 ( & V_76 ) ;
}
static int F_52 ( struct V_5 * V_6 , T_6 V_77 )
{
F_53 ( V_6 ) ;
F_54 ( V_6 ) ;
F_55 ( V_6 , F_56 ( V_6 , V_77 ) ) ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 )
{
int V_78 ;
F_55 ( V_6 , 0 ) ;
V_78 = F_58 ( V_6 ) ;
if ( V_78 )
return V_78 ;
F_59 ( V_6 ) ;
return 0 ;
}
static void F_60 ( struct V_5 * V_6 ,
struct V_79 * V_80 )
{
int V_15 , V_81 ;
for ( V_15 = 0 ; V_15 < F_11 ( V_80 -> V_82 ) ; V_15 ++ )
for ( V_81 = 0 ; V_81 < V_80 -> V_82 [ V_15 ] . V_83 ; V_81 ++ ) {
V_80 -> V_82 [ V_15 ] . V_84 [ V_81 ] . V_85 = sizeof( V_6 ) ;
V_80 -> V_82 [ V_15 ] . V_84 [ V_81 ] . V_28 = & V_6 ;
}
}
static int F_61 ( struct V_5 * V_6 ,
const struct V_86 * V_87 )
{
int V_78 , V_15 ;
struct V_79 * V_88 ;
F_62 ( & V_6 -> V_26 , L_6 , V_11 ) ;
V_78 = F_58 ( V_6 ) ;
if ( V_78 ) {
F_63 ( & V_6 -> V_26 , L_7 ) ;
return V_78 ;
}
V_78 = F_64 ( V_6 ) ;
if ( V_78 )
F_62 ( & V_6 -> V_26 , L_8 ) ;
V_88 = V_87 -> V_32 == V_89 ?
& V_90 [ V_91 ] :
& V_90 [ V_92 ] ;
F_60 ( V_6 , V_88 ) ;
if ( ! F_2 ( V_6 ) )
F_8 ( V_6 , V_93 ) ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ ) {
V_78 = F_65 ( & V_6 -> V_26 , - 1 ,
V_88 -> V_82 [ V_15 ] . V_84 ,
V_88 -> V_82 [ V_15 ] . V_83 ,
& V_6 -> V_58 [ V_15 ] ,
0 , NULL ) ;
if ( V_78 ) {
F_63 ( & V_6 -> V_26 ,
L_9 , V_15 , V_78 ) ;
goto V_94;
}
}
return 0 ;
V_94:
F_66 ( & V_6 -> V_26 ) ;
F_54 ( V_6 ) ;
F_67 ( V_6 ) ;
return V_78 ;
}
static int T_5 F_68 ( void )
{
F_47 ( L_6 , V_11 ) ;
return F_69 ( & V_95 ) ;
}
