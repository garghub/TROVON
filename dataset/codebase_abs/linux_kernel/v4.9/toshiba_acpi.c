static inline void F_1 ( T_1 * V_1 , T_1 V_2 , int V_3 )
{
* V_1 = ( * V_1 & ~ V_2 ) | ( V_2 * V_3 ) ;
}
static int F_2 ( const char * V_4 , int V_5 )
{
T_2 V_6 ;
V_6 = F_3 ( NULL , ( char * ) V_4 , V_5 ) ;
return ( V_6 == V_7 ) ? 0 : - V_8 ;
}
static T_2 F_4 ( struct V_9 * V_10 ,
const T_1 V_11 [ V_12 ] , T_1 V_13 [ V_12 ] )
{
union V_14 V_15 [ V_12 ] , V_16 [ V_12 + 1 ] ;
struct V_17 V_18 ;
struct V_19 V_20 ;
T_2 V_6 ;
int V_21 ;
V_18 . V_22 = V_12 ;
V_18 . V_23 = V_15 ;
for ( V_21 = 0 ; V_21 < V_12 ; ++ V_21 ) {
V_15 [ V_21 ] . type = V_24 ;
V_15 [ V_21 ] . integer . V_3 = V_11 [ V_21 ] ;
}
V_20 . V_25 = sizeof( V_16 ) ;
V_20 . V_23 = V_16 ;
V_6 = F_5 ( V_10 -> V_26 -> V_27 ,
( char * ) V_10 -> V_28 , & V_18 ,
& V_20 ) ;
if ( ( V_6 == V_7 ) && ( V_16 -> V_29 . V_22 <= V_12 ) ) {
for ( V_21 = 0 ; V_21 < V_16 -> V_29 . V_22 ; ++ V_21 )
V_13 [ V_21 ] = V_16 -> V_29 . V_30 [ V_21 ] . integer . V_3 ;
}
return V_6 ;
}
static T_1 F_6 ( struct V_9 * V_10 , T_1 V_31 , T_1 V_32 )
{
T_1 V_11 [ V_12 ] = { V_33 , V_31 , V_32 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
return F_7 ( V_6 ) ? V_13 [ 0 ] : V_34 ;
}
static T_1 F_8 ( struct V_9 * V_10 , T_1 V_31 , T_1 * V_35 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_31 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) )
return V_34 ;
* V_35 = V_13 [ 2 ] ;
return V_13 [ 0 ] ;
}
static int F_10 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_37 , 0 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_1 ) ;
return 0 ;
}
if ( V_13 [ 0 ] == V_38 ) {
return 1 ;
} else if ( V_13 [ 0 ] == V_39 ) {
F_12 ( L_2 ) ;
return 1 ;
} else if ( V_13 [ 0 ] == V_40 ) {
return 1 ;
} else if ( V_13 [ 0 ] == V_41 ) {
F_12 ( L_3 ) ;
}
return 0 ;
}
static void F_13 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_42 , 0 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_4 ) ;
return;
}
if ( V_13 [ 0 ] == V_38 )
return;
else if ( V_13 [ 0 ] == V_43 )
F_12 ( L_5 ) ;
else if ( V_13 [ 0 ] == V_41 )
F_12 ( L_3 ) ;
}
static T_1 F_14 ( struct V_9 * V_10 , T_1 V_31 , T_1 * V_35 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_31 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) )
return V_34 ;
* V_35 = V_13 [ 2 ] ;
return V_13 [ 0 ] ;
}
static T_1 F_15 ( struct V_9 * V_10 , T_1 V_31 , T_1 V_32 )
{
T_1 V_11 [ V_12 ] = { V_45 , V_31 , V_32 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
return F_7 ( V_6 ) ? V_13 [ 0 ] : V_34 ;
}
static void F_16 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_46 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_10 -> V_47 = 0 ;
V_10 -> V_48 = false ;
if ( ! F_10 ( V_10 ) )
return;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_6 ) ;
return;
}
if ( V_13 [ 0 ] != V_49 )
return;
V_10 -> V_47 = 1 ;
}
static void F_17 ( struct V_50 * V_51 ,
enum V_52 V_53 )
{
struct V_9 * V_10 = F_18 ( V_51 ,
struct V_9 , V_54 ) ;
T_1 V_55 ;
T_1 V_56 ;
if ( ! F_10 ( V_10 ) )
return;
V_56 = V_53 ? 1 : 0 ;
V_55 = F_15 ( V_10 , V_46 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_7 ) ;
}
static enum V_52 F_19 ( struct V_50 * V_51 )
{
struct V_9 * V_10 = F_18 ( V_51 ,
struct V_9 , V_54 ) ;
T_1 V_55 ;
T_1 V_56 ;
if ( ! F_10 ( V_10 ) )
return V_57 ;
V_55 = F_14 ( V_10 , V_46 , & V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_11 ( L_7 ) ;
return V_57 ;
} else if ( V_55 != V_49 ) {
return V_57 ;
}
return V_56 ? V_58 : V_57 ;
}
static void F_20 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_59 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_10 -> V_60 = 0 ;
V_10 -> V_61 = false ;
V_10 -> V_62 = false ;
if ( ! F_10 ( V_10 ) )
return;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_8 ) ;
return;
}
if ( V_13 [ 0 ] != V_49 )
return;
if ( V_13 [ 3 ] == V_63 )
V_10 -> V_64 = 2 ;
else
V_10 -> V_64 = 1 ;
V_10 -> V_65 = V_13 [ 2 ] & V_66 ;
V_10 -> V_67 = V_13 [ 2 ] >> V_68 ;
V_10 -> V_60 = 1 ;
}
static int F_21 ( struct V_9 * V_10 , T_1 time )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_59 , time ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_9 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_22 ( struct V_9 * V_10 , T_1 * time )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_59 , time ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_10 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static enum V_52 F_23 ( struct V_50 * V_51 )
{
struct V_9 * V_10 = F_18 ( V_51 ,
struct V_9 , V_70 ) ;
T_1 V_55 ;
T_1 V_56 ;
V_55 = F_8 ( V_10 , V_71 , & V_56 ) ;
if ( V_55 == V_34 ) {
F_11 ( L_11 ) ;
return V_57 ;
} else if ( V_55 != V_49 ) {
return V_57 ;
}
return V_56 ? V_58 : V_57 ;
}
static void F_24 ( struct V_50 * V_51 ,
enum V_52 V_53 )
{
struct V_9 * V_10 = F_18 ( V_51 ,
struct V_9 , V_70 ) ;
T_1 V_55 ;
T_1 V_56 ;
V_56 = V_53 ? 1 : 0 ;
V_55 = F_6 ( V_10 , V_71 , V_56 ) ;
if ( V_55 == V_34 )
F_11 ( L_12 ) ;
}
static int F_25 ( struct V_9 * V_10 , T_1 V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_72 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_13 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_26 ( struct V_9 * V_10 , T_1 * V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_72 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_14 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static void F_27 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_73 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_10 -> V_74 = 0 ;
V_10 -> V_75 = false ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_15 ) ;
return;
}
if ( V_13 [ 0 ] == V_76 ) {
V_11 [ 3 ] = 1 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_15 ) ;
return;
}
if ( V_13 [ 0 ] != V_49 )
return;
V_10 -> V_74 = 1 ;
}
}
static enum V_52
F_28 ( struct V_50 * V_51 )
{
struct V_9 * V_10 = F_18 ( V_51 ,
struct V_9 , V_77 ) ;
T_1 V_11 [ V_12 ] = { V_36 , V_73 , 0 , 1 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_15 ) ;
return V_57 ;
}
if ( V_13 [ 0 ] != V_49 )
return V_57 ;
return V_13 [ 2 ] ? V_58 : V_57 ;
}
static void F_29 ( struct V_50 * V_51 ,
enum V_52 V_53 )
{
struct V_9 * V_10 = F_18 ( V_51 ,
struct V_9 , V_77 ) ;
T_1 V_11 [ V_12 ] = { V_33 , V_73 , 0 , 1 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_11 [ 2 ] = ( V_53 ) ? 1 : 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) )
F_11 ( L_16 ) ;
}
static void F_30 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_78 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_10 -> V_79 = 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_17 ) ;
return;
}
if ( V_13 [ 0 ] != V_49 )
return;
V_10 -> V_79 = 1 ;
}
static int F_31 ( struct V_9 * V_10 ,
T_1 * V_80 , T_1 * V_81 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_82 , 0 , 1 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_17 ) ;
return - V_8 ;
}
if ( V_13 [ 0 ] == V_40 )
return - V_69 ;
if ( V_13 [ 0 ] != V_49 )
return - V_8 ;
* V_80 = V_13 [ 2 ] ;
* V_81 = V_13 [ 4 ] ;
return 0 ;
}
static void F_32 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_83 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_10 -> V_84 = 0 ;
if ( ! F_10 ( V_10 ) )
return;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_18 ) ;
F_13 ( V_10 ) ;
return;
}
if ( V_13 [ 0 ] != V_49 ) {
F_13 ( V_10 ) ;
return;
}
V_10 -> V_85 = V_13 [ 4 ] ;
V_11 [ 5 ] = V_86 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_18 ) ;
return;
}
if ( V_13 [ 0 ] != V_49 )
return;
V_10 -> V_87 = V_13 [ 2 ] ;
V_10 -> V_84 = 1 ;
}
static int F_33 ( struct V_9 * V_10 ,
T_1 * V_88 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_83 , V_88 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_19 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_34 ( struct V_9 * V_10 ,
T_1 V_88 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_83 , V_88 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_19 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_35 ( struct V_9 * V_10 ,
T_1 * V_88 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_83 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_11 [ 5 ] = V_86 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_20 ) ;
return - V_8 ;
}
if ( V_13 [ 0 ] == V_40 )
return - V_69 ;
if ( V_13 [ 0 ] != V_49 )
return - V_8 ;
* V_88 = V_13 [ 2 ] ;
return 0 ;
}
static int F_36 ( struct V_9 * V_10 ,
T_1 V_88 )
{
T_1 V_11 [ V_12 ] = { V_45 , V_83 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_11 [ 2 ] = V_88 ;
V_11 [ 5 ] = V_86 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_21 ) ;
return - V_8 ;
}
if ( V_13 [ 0 ] == V_40 )
return - V_69 ;
return V_13 [ 0 ] == V_49 ? 0 : - V_8 ;
}
static int F_37 ( struct V_9 * V_10 ,
T_1 * V_56 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_83 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_11 [ 5 ] = V_89 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_22 ) ;
return - V_8 ;
}
if ( V_13 [ 0 ] == V_40 )
return - V_69 ;
if ( V_13 [ 0 ] != V_49 && V_13 [ 0 ] != V_90 )
return - V_8 ;
* V_56 = V_13 [ 2 ] ;
return 0 ;
}
static int F_38 ( struct V_9 * V_10 ,
T_1 V_56 )
{
T_1 V_11 [ V_12 ] = { V_45 , V_83 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_11 [ 2 ] = V_56 ;
V_11 [ 5 ] = V_89 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_23 ) ;
return - V_8 ;
}
if ( V_13 [ 0 ] == V_40 )
return - V_69 ;
return ( V_13 [ 0 ] == V_49 || V_13 [ 0 ] == V_90 ) ? 0 : - V_8 ;
}
static int F_39 ( struct V_9 * V_10 , T_1 * V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_91 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_24 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_40 ( struct V_9 * V_10 , T_1 V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_91 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_25 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_41 ( struct V_9 * V_10 , T_1 * V_88 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_92 , V_88 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_26 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return ( V_55 == V_49 || V_55 == V_90 ) ? 0 : - V_8 ;
}
static int F_42 ( struct V_9 * V_10 , T_1 V_88 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_92 , V_88 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_27 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return ( V_55 == V_49 || V_55 == V_90 ) ? 0 : - V_8 ;
}
static int F_43 ( struct V_9 * V_10 , T_1 * V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_93 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_28 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_44 ( struct V_9 * V_10 , T_1 V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_93 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_29 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_45 ( struct V_9 * V_10 , T_1 * V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_94 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_30 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return ( V_55 == V_49 || V_55 == V_90 ) ? 0 : - V_8 ;
}
static int F_46 ( struct V_9 * V_10 , T_1 V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_94 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_31 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return ( V_55 == V_49 || V_55 == V_90 ) ? 0 : - V_8 ;
}
static int F_47 ( struct V_9 * V_10 ,
T_1 * type )
{
T_1 V_11 [ V_12 ] = { V_36 , V_95 , 0x03 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_32 ) ;
return - V_8 ;
}
if ( V_13 [ 0 ] == V_40 )
return - V_69 ;
if ( V_13 [ 0 ] != V_49 )
return - V_8 ;
* type = V_13 [ 3 ] ;
return 0 ;
}
static int F_48 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_96 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_11 [ 3 ] = V_97 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_33 ) ;
return - V_8 ;
}
if ( V_13 [ 0 ] == V_40 )
return - V_69 ;
if ( V_13 [ 0 ] != V_49 )
return - V_8 ;
V_10 -> V_98 = ! ! ( V_13 [ 2 ] & V_97 ) ;
return 0 ;
}
static void F_49 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_96 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_10 -> V_99 = 0 ;
V_11 [ 3 ] = V_100 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_34 ) ;
return;
}
if ( V_13 [ 0 ] != V_49 )
return;
V_10 -> V_99 = ( V_13 [ 2 ] == V_101 ) ;
}
static int F_50 ( struct V_9 * V_10 , T_1 V_56 )
{
T_1 V_11 [ V_12 ] = { V_33 , V_96 , V_56 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_11 [ 3 ] = V_101 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_35 ) ;
return - V_8 ;
}
if ( V_13 [ 0 ] == V_40 )
return - V_69 ;
if ( V_13 [ 0 ] != V_49 )
return - V_8 ;
V_11 [ 3 ] = V_102 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_36 ) ;
return - V_8 ;
}
if ( V_13 [ 0 ] == V_40 )
return - V_69 ;
return V_13 [ 0 ] == V_49 ? 0 : - V_8 ;
}
static void F_51 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_103 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_10 -> V_104 = 0 ;
V_10 -> V_105 = 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_37 ) ;
return;
}
if ( V_13 [ 0 ] != V_49 && V_13 [ 0 ] != V_90 )
return;
V_10 -> V_104 = 1 ;
V_10 -> V_105 = V_13 [ 3 ] ;
}
static int F_52 ( struct V_9 * V_10 , T_1 * V_56 )
{
T_1 V_55 = F_8 ( V_10 , V_103 , V_56 ) ;
if ( V_55 == V_34 )
F_11 ( L_37 ) ;
if ( V_55 == V_40 )
return - V_69 ;
return ( V_55 == V_49 || V_55 == V_90 ) ? 0 : - V_8 ;
}
static int F_53 ( struct V_9 * V_10 , T_1 V_56 )
{
T_1 V_55 = F_6 ( V_10 , V_103 , V_56 ) ;
if ( V_55 == V_34 )
F_11 ( L_38 ) ;
if ( V_55 == V_40 )
return - V_69 ;
return ( V_55 == V_49 || V_55 == V_90 ) ? 0 : - V_8 ;
}
static int F_54 ( struct V_9 * V_10 , T_1 * V_6 )
{
T_1 V_55 = F_8 ( V_10 , V_106 , V_6 ) ;
if ( V_55 == V_34 )
F_11 ( L_39 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_55 ( struct V_9 * V_10 , T_1 V_6 )
{
T_1 V_55 = F_6 ( V_10 , V_106 , ! V_6 ) ;
if ( V_55 == V_34 )
F_11 ( L_40 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_56 ( struct V_9 * V_10 )
{
int V_53 = 0 ;
T_1 V_55 ;
T_1 V_3 ;
if ( V_10 -> V_107 ) {
int V_108 = F_54 ( V_10 , & V_3 ) ;
if ( V_108 )
return V_108 ;
if ( V_3 )
return 0 ;
V_53 ++ ;
}
V_55 = F_8 ( V_10 , V_109 , & V_3 ) ;
if ( V_55 == V_34 )
F_11 ( L_41 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ?
V_53 + ( V_3 >> V_110 ) :
- V_8 ;
}
static int F_57 ( struct V_111 * V_112 )
{
struct V_9 * V_10 = F_58 ( V_112 ) ;
return F_56 ( V_10 ) ;
}
static int F_59 ( struct V_113 * V_114 , void * V_115 )
{
struct V_9 * V_10 = V_114 -> V_116 ;
int V_117 ;
int V_3 ;
if ( ! V_10 -> V_118 )
return - V_69 ;
V_117 = V_10 -> V_118 -> V_119 . V_120 + 1 ;
V_3 = F_57 ( V_10 -> V_118 ) ;
if ( V_3 < 0 ) {
F_11 ( L_42 ) ;
return V_3 ;
}
F_60 ( V_114 , L_43 , V_3 ) ;
F_60 ( V_114 , L_44 , V_117 ) ;
return 0 ;
}
static int F_61 ( struct V_121 * V_121 , struct V_122 * V_122 )
{
return F_62 ( V_122 , F_59 , F_63 ( V_121 ) ) ;
}
static int F_64 ( struct V_9 * V_10 , int V_3 )
{
T_1 V_55 ;
if ( V_10 -> V_107 ) {
int V_108 = F_55 ( V_10 , ! V_3 ) ;
if ( V_108 )
return V_108 ;
if ( V_3 )
V_3 -- ;
}
V_3 = V_3 << V_110 ;
V_55 = F_6 ( V_10 , V_109 , V_3 ) ;
if ( V_55 == V_34 )
F_11 ( L_45 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_65 ( struct V_111 * V_112 )
{
struct V_9 * V_10 = F_58 ( V_112 ) ;
return F_64 ( V_10 , V_112 -> V_119 . V_53 ) ;
}
static T_3 F_66 ( struct V_122 * V_122 , const char T_4 * V_123 ,
T_5 V_22 , T_6 * V_124 )
{
struct V_9 * V_10 = F_63 ( F_67 ( V_122 ) ) ;
char V_125 [ 42 ] ;
T_5 V_126 ;
int V_117 ;
int V_3 ;
V_126 = F_68 ( V_22 , sizeof( V_125 ) - 1 ) ;
if ( F_69 ( V_125 , V_123 , V_126 ) )
return - V_127 ;
V_125 [ V_126 ] = '\0' ;
V_117 = V_10 -> V_118 -> V_119 . V_120 + 1 ;
if ( sscanf ( V_125 , L_46 , & V_3 ) != 1 &&
V_3 < 0 && V_3 > V_117 )
return - V_128 ;
if ( F_64 ( V_10 , V_3 ) )
return - V_8 ;
return V_22 ;
}
static int F_70 ( struct V_9 * V_10 , T_1 * V_6 )
{
T_1 V_55 = F_8 ( V_10 , V_129 , V_6 ) ;
if ( V_55 == V_34 )
F_11 ( L_47 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_71 ( struct V_113 * V_114 , void * V_115 )
{
struct V_9 * V_10 = V_114 -> V_116 ;
int V_130 , V_131 , V_132 ;
T_1 V_3 ;
if ( F_70 ( V_10 , & V_3 ) )
return - V_8 ;
V_130 = ( V_3 & V_133 ) ? 1 : 0 ;
V_131 = ( V_3 & V_134 ) ? 1 : 0 ;
V_132 = ( V_3 & V_135 ) ? 1 : 0 ;
F_60 ( V_114 , L_48 , V_130 ) ;
F_60 ( V_114 , L_49 , V_131 ) ;
F_60 ( V_114 , L_50 , V_132 ) ;
return 0 ;
}
static int F_72 ( struct V_121 * V_121 , struct V_122 * V_122 )
{
return F_62 ( V_122 , F_71 , F_63 ( V_121 ) ) ;
}
static T_3 F_73 ( struct V_122 * V_122 , const char T_4 * V_123 ,
T_5 V_22 , T_6 * V_124 )
{
struct V_9 * V_10 = F_63 ( F_67 ( V_122 ) ) ;
char * V_136 ;
char * V_125 ;
int V_137 , V_138 , V_139 ;
int V_140 = V_22 ;
int V_3 ;
int V_108 ;
T_1 V_141 ;
V_125 = F_74 ( V_22 + 1 , V_142 ) ;
if ( ! V_125 )
return - V_143 ;
if ( F_69 ( V_125 , V_123 , V_22 ) ) {
F_75 ( V_125 ) ;
return - V_127 ;
}
V_125 [ V_22 ] = '\0' ;
V_136 = V_125 ;
while ( V_140 ) {
if ( sscanf ( V_136 , L_51 , & V_3 ) == 1 )
V_137 = V_3 & 1 ;
else if ( sscanf ( V_136 , L_52 , & V_3 ) == 1 )
V_138 = V_3 & 1 ;
else if ( sscanf ( V_136 , L_53 , & V_3 ) == 1 )
V_139 = V_3 & 1 ;
do {
++ V_136 ;
-- V_140 ;
} while ( V_140 && * ( V_136 - 1 ) != ';' );
}
F_75 ( V_125 ) ;
V_137 = V_138 = V_139 = - 1 ;
V_108 = F_70 ( V_10 , & V_141 ) ;
if ( ! V_108 ) {
unsigned int V_144 = V_141 ;
if ( V_137 != - 1 )
F_1 ( & V_144 , V_133 , V_137 ) ;
if ( V_138 != - 1 )
F_1 ( & V_144 , V_134 , V_138 ) ;
if ( V_139 != - 1 )
F_1 ( & V_144 , V_135 , V_139 ) ;
if ( V_144 != V_141 )
V_108 = F_2 ( V_145 , V_144 ) ;
}
return V_108 ? - V_8 : V_22 ;
}
static int F_76 ( struct V_9 * V_10 , T_1 * V_6 )
{
T_1 V_55 = F_8 ( V_10 , V_146 , V_6 ) ;
if ( V_55 == V_34 )
F_11 ( L_54 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_77 ( struct V_9 * V_10 , T_1 V_6 )
{
T_1 V_55 = F_6 ( V_10 , V_146 , V_6 ) ;
if ( V_55 == V_34 )
F_11 ( L_55 ) ;
else if ( V_55 == V_40 )
return - V_69 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_78 ( struct V_113 * V_114 , void * V_115 )
{
struct V_9 * V_10 = V_114 -> V_116 ;
T_1 V_3 ;
if ( F_76 ( V_10 , & V_3 ) )
return - V_8 ;
F_60 ( V_114 , L_56 , ( V_3 > 0 ) ) ;
F_60 ( V_114 , L_57 , V_10 -> V_147 ) ;
return 0 ;
}
static int F_79 ( struct V_121 * V_121 , struct V_122 * V_122 )
{
return F_62 ( V_122 , F_78 , F_63 ( V_121 ) ) ;
}
static T_3 F_80 ( struct V_122 * V_122 , const char T_4 * V_123 ,
T_5 V_22 , T_6 * V_124 )
{
struct V_9 * V_10 = F_63 ( F_67 ( V_122 ) ) ;
char V_125 [ 42 ] ;
T_5 V_126 ;
int V_3 ;
V_126 = F_68 ( V_22 , sizeof( V_125 ) - 1 ) ;
if ( F_69 ( V_125 , V_123 , V_126 ) )
return - V_127 ;
V_125 [ V_126 ] = '\0' ;
if ( sscanf ( V_125 , L_58 , & V_3 ) != 1 &&
V_3 != 0 && V_3 != 1 )
return - V_128 ;
if ( F_77 ( V_10 , V_3 ) )
return - V_8 ;
V_10 -> V_147 = V_3 ;
return V_22 ;
}
static int F_81 ( struct V_113 * V_114 , void * V_115 )
{
struct V_9 * V_10 = V_114 -> V_116 ;
F_60 ( V_114 , L_59 , V_10 -> V_148 ) ;
F_60 ( V_114 , L_60 , V_10 -> V_149 ) ;
return 0 ;
}
static int F_82 ( struct V_121 * V_121 , struct V_122 * V_122 )
{
return F_62 ( V_122 , F_81 , F_63 ( V_121 ) ) ;
}
static T_3 F_83 ( struct V_122 * V_122 , const char T_4 * V_123 ,
T_5 V_22 , T_6 * V_124 )
{
struct V_9 * V_10 = F_63 ( F_67 ( V_122 ) ) ;
char V_125 [ 42 ] ;
T_5 V_126 ;
int V_3 ;
V_126 = F_68 ( V_22 , sizeof( V_125 ) - 1 ) ;
if ( F_69 ( V_125 , V_123 , V_126 ) )
return - V_127 ;
V_125 [ V_126 ] = '\0' ;
if ( sscanf ( V_125 , L_61 , & V_3 ) == 1 && V_3 == 0 )
V_10 -> V_148 = 0 ;
else
return - V_128 ;
return V_22 ;
}
static int F_84 ( struct V_113 * V_114 , void * V_115 )
{
F_60 ( V_114 , L_62 , V_150 ) ;
F_60 ( V_114 , L_63 , V_151 ) ;
return 0 ;
}
static int F_85 ( struct V_121 * V_121 , struct V_122 * V_122 )
{
return F_62 ( V_122 , F_84 , F_63 ( V_121 ) ) ;
}
static void F_86 ( struct V_9 * V_10 )
{
if ( V_10 -> V_118 )
F_87 ( L_64 , V_152 | V_153 , V_154 ,
& V_155 , V_10 ) ;
if ( V_10 -> V_156 )
F_87 ( L_65 , V_152 | V_153 , V_154 ,
& V_157 , V_10 ) ;
if ( V_10 -> V_158 )
F_87 ( L_66 , V_152 | V_153 , V_154 ,
& V_159 , V_10 ) ;
if ( V_10 -> V_160 )
F_87 ( L_67 , V_152 | V_153 , V_154 ,
& V_161 , V_10 ) ;
F_87 ( L_68 , V_152 , V_154 ,
& V_162 , V_10 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
if ( V_10 -> V_118 )
F_89 ( L_64 , V_154 ) ;
if ( V_10 -> V_156 )
F_89 ( L_65 , V_154 ) ;
if ( V_10 -> V_158 )
F_89 ( L_66 , V_154 ) ;
if ( V_10 -> V_160 )
F_89 ( L_67 , V_154 ) ;
F_89 ( L_68 , V_154 ) ;
}
static T_3 F_90 ( struct V_163 * V_10 ,
struct V_164 * V_165 , char * V_123 )
{
return sprintf ( V_123 , L_69 , V_150 ) ;
}
static T_3 F_91 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
const char * V_123 , T_5 V_22 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_56 ;
int V_108 ;
V_108 = F_93 ( V_123 , 0 , & V_56 ) ;
if ( V_108 )
return V_108 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_128 ;
V_108 = F_77 ( V_166 , V_56 ) ;
if ( V_108 )
return V_108 ;
return V_22 ;
}
static T_3 F_94 ( struct V_163 * V_10 ,
struct V_164 * V_165 , char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
T_1 V_3 ;
int V_108 ;
V_108 = F_76 ( V_166 , & V_3 ) ;
if ( V_108 )
return V_108 ;
return sprintf ( V_123 , L_70 , V_3 ) ;
}
static T_3 F_95 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
const char * V_123 , T_5 V_22 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_88 ;
int V_108 ;
V_108 = F_93 ( V_123 , 0 , & V_88 ) ;
if ( V_108 )
return V_108 ;
if ( V_166 -> V_64 == 1 ) {
if ( V_88 != V_167 && V_88 != V_168 )
return - V_128 ;
} else if ( V_166 -> V_64 == 2 ) {
if ( V_88 != V_168 && V_88 != V_169 &&
V_88 != V_170 )
return - V_128 ;
}
if ( V_166 -> V_65 != V_88 ) {
int time = V_166 -> V_67 << V_68 ;
if ( V_166 -> V_64 == 1 ) {
time |= V_166 -> V_65 ;
} else if ( V_166 -> V_64 == 2 ) {
time |= V_88 ;
}
V_108 = F_21 ( V_166 , time ) ;
if ( V_108 )
return V_108 ;
V_166 -> V_65 = V_88 ;
if ( V_166 -> V_64 == 2 &&
! V_171 -> V_62 )
F_96 ( & V_172 ) ;
}
return V_22 ;
}
static T_3 F_97 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
T_1 time ;
if ( F_22 ( V_166 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_123 , L_71 , time & V_66 ) ;
}
static T_3 F_98 ( struct V_163 * V_10 ,
struct V_164 * V_165 , char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
return sprintf ( V_123 , L_70 , V_166 -> V_64 ) ;
}
static T_3 F_99 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
if ( V_166 -> V_64 == 1 )
return sprintf ( V_123 , L_72 ,
V_167 , V_168 ) ;
return sprintf ( V_123 , L_73 ,
V_168 , V_169 , V_170 ) ;
}
static T_3 F_100 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
const char * V_123 , T_5 V_22 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int time ;
int V_108 ;
V_108 = F_93 ( V_123 , 0 , & time ) ;
if ( V_108 )
return V_108 ;
if ( V_166 -> V_64 == 1 ) {
if ( time < 0 || time > 60 )
return - V_128 ;
} else if ( V_166 -> V_64 == 2 ) {
if ( time < 1 || time > 60 )
return - V_128 ;
}
if ( V_166 -> V_67 != time ) {
time = time << V_68 ;
if ( V_166 -> V_64 == 1 )
time |= V_167 ;
else if ( V_166 -> V_64 == 2 )
time |= V_168 ;
V_108 = F_21 ( V_166 , time ) ;
if ( V_108 )
return V_108 ;
V_166 -> V_67 = time >> V_68 ;
}
return V_22 ;
}
static T_3 F_101 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
T_1 time ;
if ( F_22 ( V_166 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_123 , L_71 , time >> V_68 ) ;
}
static T_3 F_102 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
const char * V_123 , T_5 V_22 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_56 ;
int V_108 ;
V_108 = F_93 ( V_123 , 0 , & V_56 ) ;
if ( V_108 )
return V_108 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_128 ;
V_108 = F_25 ( V_166 , V_56 ) ;
if ( V_108 )
return V_108 ;
return V_22 ;
}
static T_3 F_103 ( struct V_163 * V_10 ,
struct V_164 * V_165 , char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
T_1 V_56 ;
int V_108 ;
V_108 = F_26 ( V_166 , & V_56 ) ;
if ( V_108 < 0 )
return V_108 ;
return sprintf ( V_123 , L_71 , V_56 ) ;
}
static T_3 F_104 ( struct V_163 * V_10 ,
struct V_164 * V_165 , char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
T_1 V_88 ;
int V_108 ;
V_108 = F_33 ( V_166 , & V_88 ) ;
if ( V_108 < 0 )
return V_108 ;
return sprintf ( V_123 , L_74 , V_88 & V_173 ) ;
}
static T_3 F_105 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
const char * V_123 , T_5 V_22 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_56 ;
T_1 V_88 ;
int V_108 ;
V_108 = F_93 ( V_123 , 0 , & V_56 ) ;
if ( V_108 )
return V_108 ;
if ( V_56 != 0 && V_56 != 1 && V_56 != 2 && V_56 != 3 )
return - V_128 ;
V_88 = V_166 -> V_85 ;
if ( V_56 == 0 )
V_88 |= V_174 ;
else if ( V_56 == 1 )
V_88 |= V_175 ;
else if ( V_56 == 2 )
V_88 |= V_176 ;
else if ( V_56 == 3 )
V_88 |= V_177 ;
V_108 = F_34 ( V_166 , V_88 ) ;
if ( V_108 )
return V_108 ;
return V_22 ;
}
static T_3 F_106 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_178 , V_6 ;
T_1 V_56 ;
int V_108 ;
int V_179 ;
V_108 = F_35 ( V_166 , & V_56 ) ;
if ( V_108 < 0 )
return V_108 ;
V_179 = V_56 & V_180 ;
V_6 = ( V_179 == 0x4 ) ? 1 : 0 ;
V_178 = V_56 >> V_68 ;
return sprintf ( V_123 , L_75 , V_6 , V_178 ) ;
}
static T_3 F_107 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
const char * V_123 , T_5 V_22 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
T_1 V_6 ;
int V_3 ;
int V_108 ;
int V_179 ;
V_108 = F_93 ( V_123 , 0 , & V_3 ) ;
if ( V_108 )
return V_108 ;
if ( V_3 < 0 || V_3 > 100 )
return - V_128 ;
if ( V_3 == 0 ) {
V_179 = V_166 -> V_87 << V_68 ;
V_6 = V_179 | V_181 ;
} else {
V_179 = V_3 << V_68 ;
V_6 = V_179 | V_182 ;
}
V_108 = F_36 ( V_166 , V_6 ) ;
if ( V_108 < 0 )
return V_108 ;
V_166 -> V_87 = V_6 >> V_68 ;
return V_22 ;
}
static T_3 F_108 ( struct V_163 * V_10 ,
struct V_164 * V_165 , char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
T_1 V_56 ;
int V_108 ;
V_108 = F_37 ( V_166 , & V_56 ) ;
if ( V_108 < 0 )
return V_108 ;
return sprintf ( V_123 , L_70 , V_56 ) ;
}
static T_3 F_109 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
const char * V_123 , T_5 V_22 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_56 ;
int V_108 ;
V_108 = F_93 ( V_123 , 0 , & V_56 ) ;
if ( V_108 )
return V_108 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_128 ;
V_108 = F_38 ( V_166 , V_56 ) ;
if ( V_108 )
return V_108 ;
return V_22 ;
}
static T_3 F_110 ( struct V_163 * V_10 ,
struct V_164 * V_165 , char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
T_1 V_56 ;
int V_108 ;
V_108 = F_39 ( V_166 , & V_56 ) ;
if ( V_108 < 0 )
return V_108 ;
return sprintf ( V_123 , L_70 , V_56 ) ;
}
static T_3 F_111 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
const char * V_123 , T_5 V_22 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_56 ;
int V_108 ;
V_108 = F_93 ( V_123 , 0 , & V_56 ) ;
if ( V_108 )
return V_108 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_128 ;
V_108 = F_40 ( V_166 , V_56 ) ;
if ( V_108 )
return V_108 ;
return V_22 ;
}
static T_3 F_112 ( struct V_163 * V_10 ,
struct V_164 * V_165 , char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_88 ;
int V_108 ;
V_108 = F_41 ( V_166 , & V_88 ) ;
if ( V_108 < 0 )
return V_108 ;
return sprintf ( V_123 , L_70 , V_88 ) ;
}
static T_3 F_113 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
const char * V_123 , T_5 V_22 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_88 ;
int V_108 ;
V_108 = F_93 ( V_123 , 0 , & V_88 ) ;
if ( V_108 )
return V_108 ;
if ( V_88 != 0 && V_88 != 1 )
return - V_128 ;
V_108 = F_42 ( V_166 , V_88 ) ;
if ( V_108 )
return V_108 ;
F_12 ( L_76 ) ;
return V_22 ;
}
static T_3 F_114 ( struct V_163 * V_10 ,
struct V_164 * V_165 , char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
T_1 V_56 ;
int V_108 ;
V_108 = F_43 ( V_166 , & V_56 ) ;
if ( V_108 < 0 )
return V_108 ;
return sprintf ( V_123 , L_70 , V_56 ) ;
}
static T_3 F_115 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
const char * V_123 , T_5 V_22 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_56 ;
int V_108 ;
V_108 = F_93 ( V_123 , 0 , & V_56 ) ;
if ( V_108 )
return V_108 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_128 ;
V_108 = F_44 ( V_166 , V_56 ) ;
if ( V_108 )
return V_108 ;
F_12 ( L_77 ) ;
return V_22 ;
}
static T_3 F_116 ( struct V_163 * V_10 ,
struct V_164 * V_165 , char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
T_1 V_56 ;
int V_108 ;
V_108 = F_45 ( V_166 , & V_56 ) ;
if ( V_108 < 0 )
return V_108 ;
return sprintf ( V_123 , L_70 , V_56 ) ;
}
static T_3 F_117 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
const char * V_123 , T_5 V_22 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_56 ;
int V_108 ;
V_108 = F_93 ( V_123 , 0 , & V_56 ) ;
if ( V_108 )
return V_108 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_128 ;
V_108 = F_46 ( V_166 , V_56 ) ;
if ( V_108 )
return V_108 ;
F_12 ( L_78 ) ;
return V_22 ;
}
static T_3 F_118 ( struct V_163 * V_10 ,
struct V_164 * V_165 , char * V_123 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_56 ;
int V_108 ;
V_108 = F_52 ( V_166 , & V_56 ) ;
if ( V_108 < 0 )
return V_108 ;
return sprintf ( V_123 , L_75 , V_56 , V_166 -> V_105 ) ;
}
static T_3 F_119 ( struct V_163 * V_10 ,
struct V_164 * V_165 ,
const char * V_123 , T_5 V_22 )
{
struct V_9 * V_166 = F_92 ( V_10 ) ;
int V_56 ;
int V_108 ;
V_108 = F_93 ( V_123 , 0 , & V_56 ) ;
if ( V_108 )
return V_108 ;
if ( V_56 < 0 || V_56 > V_166 -> V_105 )
return - V_128 ;
V_108 = F_53 ( V_166 , V_56 ) ;
if ( V_108 )
return V_108 ;
return V_22 ;
}
static T_7 F_120 ( struct V_183 * V_184 ,
struct V_185 * V_165 , int V_186 )
{
struct V_163 * V_10 = F_18 ( V_184 , struct V_163 , V_184 ) ;
struct V_9 * V_187 = F_92 ( V_10 ) ;
bool V_188 = true ;
if ( V_165 == & V_189 . V_165 )
V_188 = ( V_187 -> V_158 ) ? true : false ;
else if ( V_165 == & V_190 . V_165 )
V_188 = ( V_187 -> V_60 ) ? true : false ;
else if ( V_165 == & V_191 . V_165 )
V_188 = ( V_187 -> V_65 == V_168 ) ? true : false ;
else if ( V_165 == & V_192 . V_165 )
V_188 = ( V_187 -> V_193 ) ? true : false ;
else if ( V_165 == & V_194 . V_165 )
V_188 = ( V_187 -> V_84 ) ? true : false ;
else if ( V_165 == & V_195 . V_165 )
V_188 = ( V_187 -> V_84 ) ? true : false ;
else if ( V_165 == & V_196 . V_165 )
V_188 = ( V_187 -> V_197 ) ? true : false ;
else if ( V_165 == & V_198 . V_165 )
V_188 = ( V_187 -> V_199 ) ? true : false ;
else if ( V_165 == & V_200 . V_165 )
V_188 = ( V_187 -> V_201 ) ? true : false ;
else if ( V_165 == & V_202 . V_165 )
V_188 = ( V_187 -> V_203 ) ? true : false ;
else if ( V_165 == & V_204 . V_165 )
V_188 = ( V_187 -> V_205 ) ? true : false ;
else if ( V_165 == & V_206 . V_165 )
V_188 = ( V_187 -> V_104 ) ? true : false ;
return V_188 ? V_165 -> V_88 : 0 ;
}
static void F_121 ( struct V_207 * V_208 )
{
struct V_209 * V_26 = V_171 -> V_26 ;
if ( F_122 ( & V_26 -> V_10 . V_184 ,
& V_210 ) )
F_11 ( L_79 ) ;
F_123 ( V_26 -> V_211 . V_212 ,
F_124 ( & V_26 -> V_10 ) ,
0x92 , 0 ) ;
}
static int F_125 ( enum V_213 V_214 )
{
T_1 V_215 , V_216 ;
int V_108 ;
V_108 = F_31 ( V_171 , & V_215 , & V_216 ) ;
if ( V_108 < 0 )
return V_108 ;
switch ( V_214 ) {
case V_217 :
return V_215 & V_218 ?
- ( V_215 & V_219 ) : V_215 & V_219 ;
case V_220 :
return ( V_215 >> V_68 ) & V_218 ?
- ( ( V_215 >> V_68 ) & V_219 ) :
( V_215 >> V_68 ) & V_219 ;
case V_221 :
return V_216 & V_218 ?
- ( V_216 & V_219 ) : V_216 & V_219 ;
}
return V_108 ;
}
static int F_126 ( struct V_222 * V_223 ,
struct V_224 const * V_214 ,
int * V_5 , int * V_225 , long V_2 )
{
int V_108 ;
switch ( V_2 ) {
case V_226 :
V_108 = F_125 ( V_214 -> V_227 ) ;
if ( V_108 == - V_8 || V_108 == - V_69 )
return V_108 ;
* V_5 = V_108 ;
return V_228 ;
}
return - V_128 ;
}
static int F_127 ( T_8 * V_229 )
{
T_1 V_11 [ V_12 ] = { V_229 -> V_230 , V_229 -> V_231 , V_229 -> V_232 ,
V_229 -> V_233 , V_229 -> V_234 , V_229 -> V_235 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_171 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_80 ) ;
return - V_8 ;
}
V_229 -> V_230 = V_13 [ 0 ] ;
V_229 -> V_231 = V_13 [ 1 ] ;
V_229 -> V_232 = V_13 [ 2 ] ;
V_229 -> V_233 = V_13 [ 3 ] ;
V_229 -> V_234 = V_13 [ 4 ] ;
V_229 -> V_235 = V_13 [ 5 ] ;
return 0 ;
}
static long F_128 ( struct V_122 * V_236 , unsigned int V_125 ,
unsigned long V_237 )
{
T_8 T_4 * V_238 = ( T_8 T_4 * ) V_237 ;
T_8 V_229 ;
int V_108 ;
if ( ! V_238 )
return - V_128 ;
switch ( V_125 ) {
case V_239 :
if ( F_69 ( & V_229 , V_238 , sizeof( T_8 ) ) )
return - V_127 ;
V_108 = F_127 ( & V_229 ) ;
if ( V_108 )
return V_108 ;
if ( F_129 ( V_238 , & V_229 , sizeof( T_8 ) ) )
return - V_127 ;
break;
case V_240 :
if ( F_69 ( & V_229 , V_238 , sizeof( T_8 ) ) )
return - V_127 ;
if ( V_229 . V_230 != V_44 && V_229 . V_230 != V_45 )
return - V_128 ;
if ( ! F_10 ( V_171 ) )
return - V_8 ;
V_108 = F_127 ( & V_229 ) ;
F_13 ( V_171 ) ;
if ( V_108 )
return V_108 ;
if ( F_129 ( V_238 , & V_229 , sizeof( T_8 ) ) )
return - V_127 ;
break;
default:
return - V_128 ;
}
return 0 ;
}
static int F_130 ( void * V_241 , bool V_242 )
{
struct V_9 * V_10 = V_241 ;
int V_108 ;
V_108 = F_48 ( V_10 ) ;
if ( V_108 )
return V_108 ;
if ( ! V_10 -> V_98 )
return 0 ;
return F_50 ( V_10 , ! V_242 ) ;
}
static void F_131 ( struct V_243 * V_243 , void * V_241 )
{
struct V_9 * V_10 = V_241 ;
if ( F_48 ( V_10 ) )
return;
F_132 ( V_10 -> V_244 , ! V_10 -> V_98 ) ;
}
static int F_133 ( struct V_9 * V_10 )
{
int V_108 = F_48 ( V_10 ) ;
if ( V_108 )
return V_108 ;
V_10 -> V_244 = F_134 ( L_81 ,
& V_10 -> V_26 -> V_10 ,
V_245 ,
& V_246 ,
V_10 ) ;
if ( ! V_10 -> V_244 ) {
F_11 ( L_82 ) ;
return - V_143 ;
}
F_132 ( V_10 -> V_244 , ! V_10 -> V_98 ) ;
V_108 = F_135 ( V_10 -> V_244 ) ;
if ( V_108 ) {
F_11 ( L_83 ) ;
F_136 ( V_10 -> V_244 ) ;
}
return V_108 ;
}
static int F_137 ( struct V_9 * V_10 )
{
T_2 V_6 ;
T_1 V_55 ;
V_6 = F_5 ( V_10 -> V_26 -> V_27 ,
L_84 , NULL , NULL ) ;
if ( F_9 ( V_6 ) )
return - V_69 ;
if ( V_10 -> V_201 && V_10 -> V_247 )
V_55 = F_6 ( V_10 , V_248 ,
V_249 ) ;
else
V_55 = F_6 ( V_10 , V_248 , V_250 ) ;
if ( V_55 == V_34 )
return - V_8 ;
else if ( V_55 == V_40 )
return - V_69 ;
return 0 ;
}
static bool F_138 ( unsigned char V_241 , unsigned char V_251 ,
struct V_252 * V_253 )
{
if ( V_251 & V_254 )
return false ;
if ( F_139 ( V_241 == 0xe0 ) )
return false ;
if ( ( V_241 & 0x7f ) == V_255 ) {
F_96 ( & V_171 -> V_256 ) ;
return true ;
}
return false ;
}
static void F_140 ( struct V_207 * V_208 )
{
T_9 V_257 = F_141 () ;
T_2 V_6 ;
if ( ! V_257 )
return;
V_6 = F_5 ( V_257 , L_85 , NULL , NULL ) ;
if ( F_9 ( V_6 ) )
F_11 ( L_86 ) ;
}
static int F_142 ( struct V_9 * V_10 )
{
unsigned long long V_3 ;
T_2 V_6 ;
V_6 = F_143 ( V_10 -> V_26 -> V_27 , L_87 ,
NULL , & V_3 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_88 ) ;
return - V_8 ;
}
return V_3 ;
}
static void F_144 ( struct V_9 * V_10 ,
int V_258 )
{
if ( V_258 == 0x100 )
return;
if ( V_258 & 0x80 )
return;
if ( ! F_145 ( V_10 -> V_160 , V_258 , 1 , true ) )
F_12 ( L_89 , V_258 ) ;
}
static void F_146 ( struct V_9 * V_10 )
{
if ( V_10 -> V_259 ) {
int V_258 = F_142 ( V_10 ) ;
if ( V_258 < 0 ) {
F_11 ( L_90 ) ;
} else if ( V_258 != 0 ) {
F_144 ( V_10 , V_258 ) ;
V_10 -> V_148 = 1 ;
V_10 -> V_149 = V_258 ;
}
} else if ( V_10 -> V_260 ) {
T_1 V_55 ;
T_1 V_3 ;
int V_261 = 3 ;
do {
V_55 = F_8 ( V_10 , V_262 , & V_3 ) ;
switch ( V_55 ) {
case V_49 :
F_144 ( V_10 , ( int ) V_3 ) ;
V_10 -> V_148 = 1 ;
V_10 -> V_149 = V_3 ;
break;
case V_40 :
V_55 = F_6 ( V_10 , V_262 , 1 ) ;
if ( V_55 == V_49 )
F_147 ( L_91 ) ;
default:
V_261 -- ;
break;
}
} while ( V_261 && V_55 != V_263 );
}
}
static int F_148 ( struct V_9 * V_10 )
{
const struct V_264 * V_265 = V_266 ;
T_9 V_257 ;
int error ;
if ( V_267 ) {
F_12 ( L_92 ) ;
return 0 ;
}
if ( F_149 ( V_268 ) ) {
F_12 ( L_93 ) ;
return 0 ;
}
error = F_137 ( V_10 ) ;
if ( error )
return error ;
if ( F_47 ( V_10 , & V_10 -> V_269 ) )
F_147 ( L_94 ) ;
V_10 -> V_160 = F_150 () ;
if ( ! V_10 -> V_160 )
return - V_143 ;
V_10 -> V_160 -> V_270 = L_95 ;
V_10 -> V_160 -> V_271 = L_96 ;
V_10 -> V_160 -> V_272 . V_273 = V_274 ;
if ( V_10 -> V_269 == V_275 ||
! V_10 -> V_201 )
V_265 = V_266 ;
else if ( V_10 -> V_269 == V_276 ||
V_10 -> V_201 )
V_265 = V_277 ;
else
F_12 ( L_97 ,
V_10 -> V_269 ) ;
error = F_151 ( V_10 -> V_160 , V_265 , NULL ) ;
if ( error )
goto V_278;
V_257 = F_141 () ;
if ( V_257 && F_152 ( V_257 , L_85 ) ) {
F_153 ( & V_10 -> V_256 , F_140 ) ;
error = F_154 ( F_138 ) ;
if ( error ) {
F_11 ( L_98 ) ;
goto V_279;
}
V_10 -> V_280 = 1 ;
}
if ( F_152 ( V_10 -> V_26 -> V_27 , L_87 ) )
V_10 -> V_259 = 1 ;
else if ( F_6 ( V_10 , V_262 , 1 ) == V_49 )
V_10 -> V_260 = 1 ;
if ( ! V_10 -> V_259 && ! V_10 -> V_260 ) {
F_155 ( L_99 ) ;
goto V_281;
}
error = F_156 ( V_10 -> V_160 ) ;
if ( error ) {
F_12 ( L_100 ) ;
goto V_281;
}
return 0 ;
V_281:
if ( V_10 -> V_280 )
F_157 ( F_138 ) ;
V_279:
F_158 ( V_10 -> V_160 ) ;
V_278:
F_159 ( V_10 -> V_160 ) ;
V_10 -> V_160 = NULL ;
return error ;
}
static int F_160 ( struct V_9 * V_10 )
{
struct V_282 V_119 ;
int V_53 ;
int V_108 ;
V_53 = F_56 ( V_10 ) ;
if ( V_53 < 0 )
return 0 ;
if ( V_10 -> V_107 && V_53 == 0 )
V_53 ++ ;
V_108 = F_64 ( V_10 , V_53 ) ;
if ( V_108 ) {
F_161 ( L_101 ) ;
return 0 ;
}
if ( V_10 -> V_107 ||
F_162 ( V_283 ) )
F_163 ( V_284 ) ;
if ( F_164 () != V_284 )
return 0 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . type = V_285 ;
V_119 . V_120 = V_286 - 1 ;
if ( V_10 -> V_107 )
V_119 . V_120 ++ ;
V_10 -> V_118 = F_165 ( L_102 ,
& V_10 -> V_26 -> V_10 ,
V_10 ,
& V_287 ,
& V_119 ) ;
if ( F_166 ( V_10 -> V_118 ) ) {
V_108 = F_167 ( V_10 -> V_118 ) ;
F_11 ( L_103 ) ;
V_10 -> V_118 = NULL ;
return V_108 ;
}
V_10 -> V_118 -> V_119 . V_53 = V_53 ;
return 0 ;
}
static void F_168 ( struct V_9 * V_10 )
{
F_12 ( L_104 ) ;
if ( V_10 -> V_160 )
F_169 ( L_105 ) ;
if ( V_10 -> V_118 )
F_169 ( L_106 ) ;
if ( V_10 -> V_156 )
F_169 ( L_107 ) ;
if ( V_10 -> V_158 )
F_169 ( L_108 ) ;
if ( V_10 -> V_107 )
F_169 ( L_109 ) ;
if ( V_10 -> V_47 )
F_169 ( L_110 ) ;
if ( V_10 -> V_60 )
F_169 ( L_111 ) ;
if ( V_10 -> V_193 )
F_169 ( L_112 ) ;
if ( V_10 -> V_74 )
F_169 ( L_113 ) ;
if ( V_10 -> V_79 )
F_169 ( L_114 ) ;
if ( V_10 -> V_84 )
F_169 ( L_115 ) ;
if ( V_10 -> V_197 )
F_169 ( L_116 ) ;
if ( V_10 -> V_199 )
F_169 ( L_117 ) ;
if ( V_10 -> V_201 )
F_169 ( L_118 ) ;
if ( V_10 -> V_203 )
F_169 ( L_119 ) ;
if ( V_10 -> V_205 )
F_169 ( L_120 ) ;
if ( V_10 -> V_99 )
F_169 ( L_121 ) ;
if ( V_10 -> V_104 )
F_169 ( L_122 ) ;
F_169 ( L_123 ) ;
}
static int F_170 ( struct V_209 * V_26 )
{
struct V_9 * V_10 = F_171 ( V_26 ) ;
F_172 ( & V_10 -> V_288 ) ;
F_88 ( V_10 ) ;
if ( V_10 -> V_79 && V_10 -> V_223 ) {
F_173 ( V_10 -> V_223 ) ;
F_174 ( V_10 -> V_223 ) ;
}
if ( V_10 -> V_289 )
F_175 ( & V_10 -> V_26 -> V_10 . V_184 ,
& V_210 ) ;
if ( V_10 -> V_280 ) {
F_157 ( F_138 ) ;
F_176 ( & V_10 -> V_256 ) ;
}
if ( V_10 -> V_160 ) {
F_177 ( V_10 -> V_160 ) ;
F_158 ( V_10 -> V_160 ) ;
}
F_178 ( V_10 -> V_118 ) ;
if ( V_10 -> V_48 )
F_179 ( & V_10 -> V_54 ) ;
if ( V_10 -> V_61 )
F_179 ( & V_10 -> V_70 ) ;
if ( V_10 -> V_75 )
F_179 ( & V_10 -> V_77 ) ;
if ( V_10 -> V_244 ) {
F_180 ( V_10 -> V_244 ) ;
F_136 ( V_10 -> V_244 ) ;
}
if ( V_171 )
V_171 = NULL ;
F_75 ( V_10 ) ;
return 0 ;
}
static const char * F_181 ( T_9 V_27 )
{
if ( F_152 ( V_27 , L_124 ) )
return L_124 ;
if ( F_152 ( V_27 , L_125 ) )
return L_125 ;
return NULL ;
}
static int F_182 ( struct V_209 * V_26 )
{
struct V_9 * V_10 ;
const char * V_290 ;
T_1 V_291 ;
int V_108 = 0 ;
if ( V_171 )
return - V_292 ;
F_12 ( L_126 ,
V_150 ) ;
V_290 = F_181 ( V_26 -> V_27 ) ;
if ( ! V_290 ) {
F_11 ( L_127 ) ;
return - V_69 ;
}
V_10 = F_183 ( sizeof( * V_10 ) , V_142 ) ;
if ( ! V_10 )
return - V_143 ;
V_10 -> V_26 = V_26 ;
V_10 -> V_28 = V_290 ;
V_10 -> V_288 . V_293 = V_294 ;
V_10 -> V_288 . V_270 = L_128 ;
V_10 -> V_288 . V_295 = & V_296 ;
V_108 = F_184 ( & V_10 -> V_288 ) ;
if ( V_108 ) {
F_11 ( L_129 ) ;
F_75 ( V_10 ) ;
return V_108 ;
}
V_26 -> V_297 = V_10 ;
F_185 ( & V_26 -> V_10 , V_10 ) ;
V_108 = F_41 ( V_10 , & V_10 -> V_247 ) ;
V_10 -> V_201 = ! V_108 ;
V_10 -> V_269 = 0 ;
if ( F_148 ( V_10 ) )
F_12 ( L_130 ) ;
V_108 = F_54 ( V_10 , & V_291 ) ;
V_10 -> V_107 = ! V_108 ;
V_108 = F_160 ( V_10 ) ;
if ( V_108 )
goto error;
F_16 ( V_10 ) ;
if ( V_10 -> V_47 ) {
V_10 -> V_54 . V_270 = L_131 ;
V_10 -> V_54 . V_120 = 1 ;
V_10 -> V_54 . V_298 = F_17 ;
V_10 -> V_54 . V_299 = F_19 ;
if ( ! F_186 ( & V_26 -> V_10 , & V_10 -> V_54 ) )
V_10 -> V_48 = true ;
}
F_27 ( V_10 ) ;
if ( V_10 -> V_74 ) {
V_10 -> V_77 . V_270 = L_132 ;
V_10 -> V_77 . V_120 = 1 ;
V_10 -> V_77 . V_298 = F_29 ;
V_10 -> V_77 . V_299 = F_28 ;
if ( ! F_186 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_77 ) )
V_10 -> V_75 = true ;
}
F_20 ( V_10 ) ;
if ( V_10 -> V_60 && V_10 -> V_65 == V_167 ) {
V_10 -> V_70 . V_270 = L_133 ;
V_10 -> V_70 . V_120 = 1 ;
V_10 -> V_70 . V_298 = F_24 ;
V_10 -> V_70 . V_299 = F_23 ;
if ( ! F_186 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_70 ) )
V_10 -> V_61 = true ;
}
V_108 = F_26 ( V_10 , & V_291 ) ;
V_10 -> V_193 = ! V_108 ;
F_30 ( V_10 ) ;
if ( V_10 -> V_79 ) {
V_10 -> V_223 = F_187 ( sizeof( * V_10 ) ) ;
if ( ! V_10 -> V_223 ) {
F_11 ( L_134 ) ;
goto V_300;
}
F_12 ( L_135 ) ;
V_10 -> V_223 -> V_301 = & V_302 ;
V_10 -> V_223 -> V_270 = L_136 ;
V_10 -> V_223 -> V_10 . V_303 = & V_26 -> V_10 ;
V_10 -> V_223 -> V_304 = V_305 ;
V_10 -> V_223 -> V_306 = V_307 ;
V_10 -> V_223 -> V_308 =
F_188 ( V_307 ) ;
V_108 = F_189 ( V_10 -> V_223 ) ;
if ( V_108 < 0 ) {
F_11 ( L_137 ) ;
F_174 ( V_10 -> V_223 ) ;
}
}
V_300:
F_32 ( V_10 ) ;
V_108 = F_37 ( V_10 , & V_291 ) ;
V_10 -> V_197 = ! V_108 ;
V_108 = F_39 ( V_10 , & V_291 ) ;
V_10 -> V_199 = ! V_108 ;
V_108 = F_43 ( V_10 , & V_291 ) ;
V_10 -> V_203 = ! V_108 ;
V_108 = F_45 ( V_10 , & V_291 ) ;
V_10 -> V_205 = ! V_108 ;
V_108 = F_70 ( V_10 , & V_291 ) ;
V_10 -> V_156 = ! V_108 ;
V_108 = F_76 ( V_10 , & V_291 ) ;
V_10 -> V_158 = ! V_108 ;
F_49 ( V_10 ) ;
if ( V_10 -> V_99 )
F_133 ( V_10 ) ;
F_51 ( V_10 ) ;
F_168 ( V_10 ) ;
V_108 = F_190 ( & V_10 -> V_26 -> V_10 . V_184 ,
& V_210 ) ;
if ( V_108 ) {
V_10 -> V_289 = 0 ;
goto error;
}
V_10 -> V_289 = ! V_108 ;
F_86 ( V_10 ) ;
V_171 = V_10 ;
return 0 ;
error:
F_170 ( V_26 ) ;
return V_108 ;
}
static void F_191 ( struct V_209 * V_26 , T_1 V_309 )
{
struct V_9 * V_10 = F_171 ( V_26 ) ;
switch ( V_309 ) {
case 0x80 :
if ( F_149 ( V_268 ) )
return;
F_146 ( V_10 ) ;
break;
case 0x81 :
case 0x82 :
case 0x83 :
F_12 ( L_138 , V_309 ) ;
break;
case 0x88 :
F_12 ( L_139 ) ;
break;
case 0x8f :
case 0x90 :
break;
case 0x8c :
case 0x8b :
F_12 ( L_140 , V_309 ) ;
break;
case 0x92 :
V_171 -> V_62 = true ;
if ( F_122 ( & V_26 -> V_10 . V_184 ,
& V_210 ) )
F_11 ( L_79 ) ;
break;
case 0x85 :
case 0x8d :
case 0x8e :
case 0x94 :
case 0x95 :
default:
F_12 ( L_141 , V_309 ) ;
break;
}
F_123 ( V_26 -> V_211 . V_212 ,
F_124 ( & V_26 -> V_10 ) ,
V_309 , ( V_309 == 0x80 ) ?
V_10 -> V_149 : 0 ) ;
}
static int F_192 ( struct V_163 * V_163 )
{
struct V_9 * V_10 = F_171 ( F_193 ( V_163 ) ) ;
if ( V_10 -> V_160 ) {
T_1 V_55 ;
V_55 = F_6 ( V_10 , V_248 , V_310 ) ;
if ( V_55 != V_49 )
F_12 ( L_142 ) ;
}
return 0 ;
}
static int F_194 ( struct V_163 * V_163 )
{
struct V_9 * V_10 = F_171 ( F_193 ( V_163 ) ) ;
if ( V_10 -> V_160 ) {
if ( F_137 ( V_10 ) )
F_12 ( L_143 ) ;
}
if ( V_10 -> V_244 ) {
if ( ! F_48 ( V_10 ) )
F_132 ( V_10 -> V_244 , ! V_10 -> V_98 ) ;
}
return 0 ;
}
static int T_10 F_195 ( void )
{
int V_108 ;
V_154 = F_196 ( V_311 , V_312 ) ;
if ( ! V_154 ) {
F_11 ( L_144 V_311 L_123 ) ;
return - V_69 ;
}
V_108 = F_197 ( & V_313 ) ;
if ( V_108 ) {
F_11 ( L_145 , V_108 ) ;
F_89 ( V_311 , V_312 ) ;
}
return V_108 ;
}
static void T_11 F_198 ( void )
{
F_199 ( & V_313 ) ;
if ( V_154 )
F_89 ( V_311 , V_312 ) ;
}
