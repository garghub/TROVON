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
struct V_14 V_15 ;
union V_16 V_17 [ V_12 ] ;
struct V_18 V_19 ;
union V_16 V_20 [ V_12 + 1 ] ;
T_2 V_6 ;
int V_21 ;
V_15 . V_22 = V_12 ;
V_15 . V_23 = V_17 ;
for ( V_21 = 0 ; V_21 < V_12 ; ++ V_21 ) {
V_17 [ V_21 ] . type = V_24 ;
V_17 [ V_21 ] . integer . V_3 = V_11 [ V_21 ] ;
}
V_19 . V_25 = sizeof( V_20 ) ;
V_19 . V_23 = V_20 ;
V_6 = F_5 ( V_10 -> V_26 -> V_27 ,
( char * ) V_10 -> V_28 , & V_15 ,
& V_19 ) ;
if ( ( V_6 == V_7 ) && ( V_20 -> V_29 . V_22 <= V_12 ) ) {
for ( V_21 = 0 ; V_21 < V_20 -> V_29 . V_22 ; ++ V_21 )
V_13 [ V_21 ] = V_20 -> V_29 . V_30 [ V_21 ] . integer . V_3 ;
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
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
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
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
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
if ( F_9 ( V_6 ) )
F_11 ( L_6 ) ;
else if ( V_13 [ 0 ] == V_49 )
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
T_1 V_56 , V_55 ;
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
if ( ! F_10 ( V_10 ) )
return;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_8 ) ;
} else if ( V_13 [ 0 ] == V_49 ) {
if ( V_13 [ 3 ] == V_62 )
V_10 -> V_63 = 2 ;
else
V_10 -> V_63 = 1 ;
V_10 -> V_64 = V_13 [ 2 ] & V_65 ;
V_10 -> V_66 = V_13 [ 2 ] >> V_67 ;
V_10 -> V_60 = 1 ;
}
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
return - V_68 ;
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
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static enum V_52 F_23 ( struct V_50 * V_51 )
{
struct V_9 * V_10 = F_18 ( V_51 ,
struct V_9 , V_69 ) ;
T_1 V_55 ;
T_1 V_56 ;
V_55 = F_8 ( V_10 , V_70 , & V_56 ) ;
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
struct V_9 , V_69 ) ;
T_1 V_55 ;
T_1 V_56 ;
V_56 = V_53 ? 1 : 0 ;
V_55 = F_6 ( V_10 , V_70 , V_56 ) ;
if ( V_55 == V_34 )
F_11 ( L_12 ) ;
}
static int F_25 ( struct V_9 * V_10 , T_1 V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_71 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_13 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_26 ( struct V_9 * V_10 , T_1 * V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_71 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_14 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static void F_27 ( struct V_9 * V_10 )
{
T_2 V_6 ;
T_1 V_11 [ V_12 ] = { V_36 , V_72 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
V_10 -> V_73 = 0 ;
V_10 -> V_74 = false ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_15 ) ;
} else if ( V_13 [ 0 ] == V_75 ) {
V_11 [ 3 ] = 1 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) )
F_11 ( L_15 ) ;
else if ( V_13 [ 0 ] == V_49 )
V_10 -> V_73 = 1 ;
}
}
static enum V_52
F_28 ( struct V_50 * V_51 )
{
struct V_9 * V_10 = F_18 ( V_51 ,
struct V_9 , V_76 ) ;
T_1 V_11 [ V_12 ] = { V_36 , V_72 , 0 , 1 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_15 ) ;
return V_57 ;
} else if ( V_13 [ 0 ] != V_49 ) {
return V_57 ;
}
return V_13 [ 2 ] ? V_58 : V_57 ;
}
static void F_29 ( struct V_50 * V_51 ,
enum V_52 V_53 )
{
struct V_9 * V_10 = F_18 ( V_51 ,
struct V_9 , V_76 ) ;
T_1 V_11 [ V_12 ] = { V_33 , V_72 , 0 , 1 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_11 [ 2 ] = ( V_53 ) ? 1 : 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) )
F_11 ( L_16 ) ;
}
static void F_30 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_77 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_10 -> V_78 = 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) )
F_11 ( L_17 ) ;
else if ( V_13 [ 0 ] == V_49 )
V_10 -> V_78 = 1 ;
}
static int F_31 ( struct V_9 * V_10 ,
T_1 * V_79 , T_1 * V_80 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_81 , 0 , 1 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_17 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_40 ) {
return - V_68 ;
} else if ( V_13 [ 0 ] == V_49 ) {
* V_79 = V_13 [ 2 ] ;
* V_80 = V_13 [ 4 ] ;
return 0 ;
}
return - V_8 ;
}
static void F_32 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_82 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_10 -> V_83 = 0 ;
if ( ! F_10 ( V_10 ) )
return;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_18 ) ;
F_13 ( V_10 ) ;
return;
} else if ( V_13 [ 0 ] == V_40 ) {
F_13 ( V_10 ) ;
return;
} else if ( V_13 [ 0 ] == V_49 ) {
V_10 -> V_84 = V_13 [ 4 ] ;
}
V_11 [ 5 ] = V_85 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_18 ) ;
} else if ( V_13 [ 0 ] == V_49 ) {
V_10 -> V_86 = V_13 [ 2 ] ;
V_10 -> V_83 = 1 ;
}
}
static int F_33 ( struct V_9 * V_10 ,
T_1 * V_87 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_82 , V_87 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_19 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_34 ( struct V_9 * V_10 ,
T_1 V_87 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_82 , V_87 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_19 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_35 ( struct V_9 * V_10 ,
T_1 * V_87 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_82 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_11 [ 5 ] = V_85 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_20 ) ;
} else if ( V_13 [ 0 ] == V_40 ) {
return - V_68 ;
} else if ( V_13 [ 0 ] == V_49 ) {
* V_87 = V_13 [ 2 ] ;
return 0 ;
}
return - V_8 ;
}
static int F_36 ( struct V_9 * V_10 ,
T_1 V_87 )
{
T_1 V_11 [ V_12 ] = { V_45 , V_82 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_11 [ 2 ] = V_87 ;
V_11 [ 5 ] = V_85 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) )
F_11 ( L_21 ) ;
else if ( V_13 [ 0 ] == V_40 )
return - V_68 ;
return V_13 [ 0 ] == V_49 ? 0 : - V_8 ;
}
static int F_37 ( struct V_9 * V_10 ,
T_1 * V_56 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_82 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_11 [ 5 ] = V_88 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_22 ) ;
} else if ( V_13 [ 0 ] == V_40 ) {
return - V_68 ;
} else if ( V_13 [ 0 ] == V_49 || V_13 [ 0 ] == V_89 ) {
* V_56 = V_13 [ 2 ] ;
return 0 ;
}
return - V_8 ;
}
static int F_38 ( struct V_9 * V_10 ,
T_1 V_56 )
{
T_1 V_11 [ V_12 ] = { V_45 , V_82 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_11 [ 2 ] = V_56 ;
V_11 [ 5 ] = V_88 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) )
F_11 ( L_23 ) ;
else if ( V_13 [ 0 ] == V_40 )
return - V_68 ;
return ( V_13 [ 0 ] == V_49 || V_13 [ 0 ] == V_89 ) ? 0 : - V_8 ;
}
static int F_39 ( struct V_9 * V_10 , T_1 * V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_90 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_24 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_40 ( struct V_9 * V_10 , T_1 V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_90 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_25 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_41 ( struct V_9 * V_10 , T_1 * V_87 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_91 , V_87 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_26 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return ( V_55 == V_49 || V_55 == V_89 ) ? 0 : - V_8 ;
}
static int F_42 ( struct V_9 * V_10 , T_1 V_87 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_91 , V_87 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_27 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return ( V_55 == V_49 || V_55 == V_89 ) ? 0 : - V_8 ;
}
static int F_43 ( struct V_9 * V_10 , T_1 * V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_92 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_28 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_44 ( struct V_9 * V_10 , T_1 V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_92 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_29 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_45 ( struct V_9 * V_10 , T_1 * V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_14 ( V_10 , V_93 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_30 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return ( V_55 == V_49 || V_55 == V_89 ) ? 0 : - V_8 ;
}
static int F_46 ( struct V_9 * V_10 , T_1 V_56 )
{
T_1 V_55 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_55 = F_15 ( V_10 , V_93 , V_56 ) ;
F_13 ( V_10 ) ;
if ( V_55 == V_34 )
F_11 ( L_31 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return ( V_55 == V_49 || V_55 == V_89 ) ? 0 : - V_8 ;
}
static int F_47 ( struct V_9 * V_10 ,
T_1 * type )
{
T_1 V_11 [ V_12 ] = { V_36 , V_94 , 0x03 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_32 ) ;
} else if ( V_13 [ 0 ] == V_40 ) {
return - V_68 ;
} else if ( V_13 [ 0 ] == V_49 ) {
* type = V_13 [ 3 ] ;
return 0 ;
}
return - V_8 ;
}
static int F_48 ( struct V_9 * V_10 , T_1 * V_6 )
{
T_1 V_55 = F_8 ( V_10 , V_95 , V_6 ) ;
if ( V_55 == V_34 )
F_11 ( L_33 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_49 ( struct V_9 * V_10 , T_1 V_6 )
{
T_1 V_55 = F_6 ( V_10 , V_95 , ! V_6 ) ;
if ( V_55 == V_34 )
F_11 ( L_34 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_50 ( struct V_9 * V_10 )
{
T_1 V_55 ;
T_1 V_3 ;
int V_53 = 0 ;
if ( V_10 -> V_96 ) {
int V_97 = F_48 ( V_10 , & V_3 ) ;
if ( V_97 )
return V_97 ;
if ( V_3 )
return 0 ;
V_53 ++ ;
}
V_55 = F_8 ( V_10 , V_98 , & V_3 ) ;
if ( V_55 == V_34 )
F_11 ( L_35 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
if ( V_55 == V_49 )
return V_53 + ( V_3 >> V_99 ) ;
return - V_8 ;
}
static int F_51 ( struct V_100 * V_101 )
{
struct V_9 * V_10 = F_52 ( V_101 ) ;
return F_50 ( V_10 ) ;
}
static int F_53 ( struct V_102 * V_103 , void * V_104 )
{
struct V_9 * V_10 = V_103 -> V_105 ;
int V_106 ;
int V_3 ;
if ( ! V_10 -> V_107 )
return - V_68 ;
V_106 = V_10 -> V_107 -> V_108 . V_109 + 1 ;
V_3 = F_51 ( V_10 -> V_107 ) ;
if ( V_3 >= 0 ) {
F_54 ( V_103 , L_36 , V_3 ) ;
F_54 ( V_103 , L_37 , V_106 ) ;
return 0 ;
}
F_11 ( L_38 ) ;
return - V_8 ;
}
static int F_55 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_56 ( V_111 , F_53 , F_57 ( V_110 ) ) ;
}
static int F_58 ( struct V_9 * V_10 , int V_3 )
{
T_1 V_55 ;
if ( V_10 -> V_96 ) {
int V_97 = F_49 ( V_10 , ! V_3 ) ;
if ( V_97 )
return V_97 ;
if ( V_3 )
V_3 -- ;
}
V_3 = V_3 << V_99 ;
V_55 = F_6 ( V_10 , V_98 , V_3 ) ;
if ( V_55 == V_34 )
F_11 ( L_39 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_59 ( struct V_100 * V_101 )
{
struct V_9 * V_10 = F_52 ( V_101 ) ;
return F_58 ( V_10 , V_101 -> V_108 . V_53 ) ;
}
static T_3 F_60 ( struct V_111 * V_111 , const char T_4 * V_112 ,
T_5 V_22 , T_6 * V_113 )
{
struct V_9 * V_10 = F_57 ( F_61 ( V_111 ) ) ;
char V_114 [ 42 ] ;
T_5 V_115 ;
int V_106 = V_10 -> V_107 -> V_108 . V_109 + 1 ;
int V_3 ;
V_115 = F_62 ( V_22 , sizeof( V_114 ) - 1 ) ;
if ( F_63 ( V_114 , V_112 , V_115 ) )
return - V_116 ;
V_114 [ V_115 ] = '\0' ;
if ( sscanf ( V_114 , L_40 , & V_3 ) != 1 &&
V_3 < 0 && V_3 > V_106 )
return - V_117 ;
if ( F_58 ( V_10 , V_3 ) )
return - V_8 ;
return V_22 ;
}
static int F_64 ( struct V_9 * V_10 , T_1 * V_6 )
{
T_1 V_55 = F_8 ( V_10 , V_118 , V_6 ) ;
if ( V_55 == V_34 )
F_11 ( L_41 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_65 ( struct V_102 * V_103 , void * V_104 )
{
struct V_9 * V_10 = V_103 -> V_105 ;
T_1 V_3 ;
if ( ! F_64 ( V_10 , & V_3 ) ) {
int V_119 = ( V_3 & V_120 ) ? 1 : 0 ;
int V_121 = ( V_3 & V_122 ) ? 1 : 0 ;
int V_123 = ( V_3 & V_124 ) ? 1 : 0 ;
F_54 ( V_103 , L_42 , V_119 ) ;
F_54 ( V_103 , L_43 , V_121 ) ;
F_54 ( V_103 , L_44 , V_123 ) ;
return 0 ;
}
return - V_8 ;
}
static int F_66 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_56 ( V_111 , F_65 , F_57 ( V_110 ) ) ;
}
static T_3 F_67 ( struct V_111 * V_111 , const char T_4 * V_112 ,
T_5 V_22 , T_6 * V_113 )
{
struct V_9 * V_10 = F_57 ( F_61 ( V_111 ) ) ;
char * V_125 ;
char * V_114 ;
int V_126 = V_22 ;
int V_127 = - 1 ;
int V_128 = - 1 ;
int V_129 = - 1 ;
int V_3 ;
int V_97 ;
T_1 V_130 ;
V_114 = F_68 ( V_22 + 1 , V_131 ) ;
if ( ! V_114 )
return - V_132 ;
if ( F_63 ( V_114 , V_112 , V_22 ) ) {
F_69 ( V_114 ) ;
return - V_116 ;
}
V_114 [ V_22 ] = '\0' ;
V_125 = V_114 ;
while ( V_126 ) {
if ( sscanf ( V_125 , L_45 , & V_3 ) == 1 )
V_127 = V_3 & 1 ;
else if ( sscanf ( V_125 , L_46 , & V_3 ) == 1 )
V_128 = V_3 & 1 ;
else if ( sscanf ( V_125 , L_47 , & V_3 ) == 1 )
V_129 = V_3 & 1 ;
do {
++ V_125 ;
-- V_126 ;
} while ( V_126 && * ( V_125 - 1 ) != ';' );
}
F_69 ( V_114 ) ;
V_97 = F_64 ( V_10 , & V_130 ) ;
if ( ! V_97 ) {
unsigned int V_133 = V_130 ;
if ( V_127 != - 1 )
F_1 ( & V_133 , V_120 , V_127 ) ;
if ( V_128 != - 1 )
F_1 ( & V_133 , V_122 , V_128 ) ;
if ( V_129 != - 1 )
F_1 ( & V_133 , V_124 , V_129 ) ;
if ( V_133 != V_130 )
V_97 = F_2 ( V_134 , V_133 ) ;
}
return V_97 ? - V_8 : V_22 ;
}
static int F_70 ( struct V_9 * V_10 , T_1 * V_6 )
{
T_1 V_55 = F_8 ( V_10 , V_135 , V_6 ) ;
if ( V_55 == V_34 )
F_11 ( L_48 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_71 ( struct V_9 * V_10 , T_1 V_6 )
{
T_1 V_55 = F_6 ( V_10 , V_135 , V_6 ) ;
if ( V_55 == V_34 )
F_11 ( L_49 ) ;
else if ( V_55 == V_40 )
return - V_68 ;
return V_55 == V_49 ? 0 : - V_8 ;
}
static int F_72 ( struct V_102 * V_103 , void * V_104 )
{
struct V_9 * V_10 = V_103 -> V_105 ;
T_1 V_3 ;
if ( F_70 ( V_10 , & V_3 ) )
return - V_8 ;
F_54 ( V_103 , L_50 , ( V_3 > 0 ) ) ;
F_54 ( V_103 , L_51 , V_10 -> V_136 ) ;
return 0 ;
}
static int F_73 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_56 ( V_111 , F_72 , F_57 ( V_110 ) ) ;
}
static T_3 F_74 ( struct V_111 * V_111 , const char T_4 * V_112 ,
T_5 V_22 , T_6 * V_113 )
{
struct V_9 * V_10 = F_57 ( F_61 ( V_111 ) ) ;
char V_114 [ 42 ] ;
T_5 V_115 ;
int V_3 ;
V_115 = F_62 ( V_22 , sizeof( V_114 ) - 1 ) ;
if ( F_63 ( V_114 , V_112 , V_115 ) )
return - V_116 ;
V_114 [ V_115 ] = '\0' ;
if ( sscanf ( V_114 , L_52 , & V_3 ) != 1 &&
V_3 != 0 && V_3 != 1 )
return - V_117 ;
if ( F_71 ( V_10 , V_3 ) )
return - V_8 ;
V_10 -> V_136 = V_3 ;
return V_22 ;
}
static int F_75 ( struct V_102 * V_103 , void * V_104 )
{
struct V_9 * V_10 = V_103 -> V_105 ;
F_54 ( V_103 , L_53 , V_10 -> V_137 ) ;
F_54 ( V_103 , L_54 , V_10 -> V_138 ) ;
return 0 ;
}
static int F_76 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_56 ( V_111 , F_75 , F_57 ( V_110 ) ) ;
}
static T_3 F_77 ( struct V_111 * V_111 , const char T_4 * V_112 ,
T_5 V_22 , T_6 * V_113 )
{
struct V_9 * V_10 = F_57 ( F_61 ( V_111 ) ) ;
char V_114 [ 42 ] ;
T_5 V_115 ;
int V_3 ;
V_115 = F_62 ( V_22 , sizeof( V_114 ) - 1 ) ;
if ( F_63 ( V_114 , V_112 , V_115 ) )
return - V_116 ;
V_114 [ V_115 ] = '\0' ;
if ( sscanf ( V_114 , L_55 , & V_3 ) == 1 && V_3 == 0 )
V_10 -> V_137 = 0 ;
else
return - V_117 ;
return V_22 ;
}
static int F_78 ( struct V_102 * V_103 , void * V_104 )
{
F_54 ( V_103 , L_56 , V_139 ) ;
F_54 ( V_103 , L_57 , V_140 ) ;
return 0 ;
}
static int F_79 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_56 ( V_111 , F_78 , F_57 ( V_110 ) ) ;
}
static void F_80 ( struct V_9 * V_10 )
{
if ( V_10 -> V_107 )
F_81 ( L_58 , V_141 | V_142 , V_143 ,
& V_144 , V_10 ) ;
if ( V_10 -> V_145 )
F_81 ( L_59 , V_141 | V_142 , V_143 ,
& V_146 , V_10 ) ;
if ( V_10 -> V_147 )
F_81 ( L_60 , V_141 | V_142 , V_143 ,
& V_148 , V_10 ) ;
if ( V_10 -> V_149 )
F_81 ( L_61 , V_141 | V_142 , V_143 ,
& V_150 , V_10 ) ;
F_81 ( L_62 , V_141 , V_143 ,
& V_151 , V_10 ) ;
}
static void F_82 ( struct V_9 * V_10 )
{
if ( V_10 -> V_107 )
F_83 ( L_58 , V_143 ) ;
if ( V_10 -> V_145 )
F_83 ( L_59 , V_143 ) ;
if ( V_10 -> V_147 )
F_83 ( L_60 , V_143 ) ;
if ( V_10 -> V_149 )
F_83 ( L_61 , V_143 ) ;
F_83 ( L_62 , V_143 ) ;
}
static T_3 F_84 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_112 )
{
return sprintf ( V_112 , L_63 , V_139 ) ;
}
static T_3 F_85 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_112 , T_5 V_22 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
int V_56 ;
int V_97 ;
V_97 = F_87 ( V_112 , 0 , & V_56 ) ;
if ( V_97 )
return V_97 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_117 ;
V_97 = F_71 ( V_155 , V_56 ) ;
if ( V_97 )
return V_97 ;
return V_22 ;
}
static T_3 F_88 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 V_3 ;
int V_97 ;
V_97 = F_70 ( V_155 , & V_3 ) ;
if ( V_97 )
return V_97 ;
return sprintf ( V_112 , L_64 , V_3 ) ;
}
static T_3 F_89 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_112 , T_5 V_22 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
int V_87 ;
int V_97 ;
V_97 = F_87 ( V_112 , 0 , & V_87 ) ;
if ( V_97 )
return V_97 ;
if ( V_155 -> V_63 == 1 ) {
if ( V_87 != V_156 && V_87 != V_157 )
return - V_117 ;
} else if ( V_155 -> V_63 == 2 ) {
if ( V_87 != V_157 && V_87 != V_158 &&
V_87 != V_159 )
return - V_117 ;
}
if ( V_155 -> V_64 != V_87 ) {
int time = V_155 -> V_66 << V_67 ;
if ( V_155 -> V_63 == 1 ) {
time |= V_155 -> V_64 ;
} else if ( V_155 -> V_63 == 2 ) {
time |= V_87 ;
}
V_97 = F_21 ( V_155 , time ) ;
if ( V_97 )
return V_97 ;
V_155 -> V_64 = V_87 ;
}
return V_22 ;
}
static T_3 F_90 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 time ;
if ( F_22 ( V_155 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_112 , L_65 , time & V_65 ) ;
}
static T_3 F_91 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
return sprintf ( V_112 , L_64 , V_155 -> V_63 ) ;
}
static T_3 F_92 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
if ( V_155 -> V_63 == 1 )
return sprintf ( V_112 , L_66 ,
V_156 , V_157 ) ;
return sprintf ( V_112 , L_67 ,
V_157 , V_158 , V_159 ) ;
}
static T_3 F_93 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_112 , T_5 V_22 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
int time ;
int V_97 ;
V_97 = F_87 ( V_112 , 0 , & time ) ;
if ( V_97 )
return V_97 ;
if ( V_155 -> V_63 == 1 ) {
if ( time < 0 || time > 60 )
return - V_117 ;
} else if ( V_155 -> V_63 == 2 ) {
if ( time < 1 || time > 60 )
return - V_117 ;
}
if ( V_155 -> V_66 != time ) {
time = time << V_67 ;
if ( V_155 -> V_63 == 1 )
time |= V_156 ;
else if ( V_155 -> V_63 == 2 )
time |= V_157 ;
V_97 = F_21 ( V_155 , time ) ;
if ( V_97 )
return V_97 ;
V_155 -> V_66 = time >> V_67 ;
}
return V_22 ;
}
static T_3 F_94 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 time ;
if ( F_22 ( V_155 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_112 , L_65 , time >> V_67 ) ;
}
static T_3 F_95 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_112 , T_5 V_22 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
int V_56 ;
int V_97 ;
V_97 = F_87 ( V_112 , 0 , & V_56 ) ;
if ( V_97 )
return V_97 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_117 ;
V_97 = F_25 ( V_155 , V_56 ) ;
if ( V_97 )
return V_97 ;
return V_22 ;
}
static T_3 F_96 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 V_56 ;
int V_97 ;
V_97 = F_26 ( V_155 , & V_56 ) ;
if ( V_97 < 0 )
return V_97 ;
return sprintf ( V_112 , L_65 , V_56 ) ;
}
static T_3 F_97 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 V_160 , V_161 , V_162 ;
T_7 V_163 , V_164 , V_80 ;
int V_97 ;
V_160 = V_161 = 0 ;
V_97 = F_31 ( V_155 , & V_160 , & V_161 ) ;
if ( V_97 < 0 )
return V_97 ;
V_163 = V_160 & V_165 ;
V_162 = V_160 >> V_67 ;
V_164 = V_162 & V_165 ;
V_80 = V_161 & V_165 ;
return sprintf ( V_112 , L_68 , V_163 , V_164 , V_80 ) ;
}
static T_3 F_98 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 V_87 ;
int V_97 ;
V_97 = F_33 ( V_155 , & V_87 ) ;
if ( V_97 < 0 )
return V_97 ;
return sprintf ( V_112 , L_69 , V_87 & V_166 ) ;
}
static T_3 F_99 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_112 , T_5 V_22 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 V_87 ;
int V_56 ;
int V_97 ;
V_97 = F_87 ( V_112 , 0 , & V_56 ) ;
if ( V_97 )
return V_97 ;
if ( V_56 != 0 && V_56 != 1 && V_56 != 2 && V_56 != 3 )
return - V_117 ;
V_87 = V_155 -> V_84 ;
if ( V_56 == 0 )
V_87 |= V_167 ;
else if ( V_56 == 1 )
V_87 |= V_168 ;
else if ( V_56 == 2 )
V_87 |= V_169 ;
else if ( V_56 == 3 )
V_87 |= V_170 ;
V_97 = F_34 ( V_155 , V_87 ) ;
if ( V_97 )
return V_97 ;
return V_22 ;
}
static T_3 F_100 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 V_56 ;
int V_171 ;
int V_6 ;
int V_97 ;
int V_162 ;
V_97 = F_35 ( V_155 , & V_56 ) ;
if ( V_97 < 0 )
return V_97 ;
V_162 = V_56 & V_172 ;
V_6 = ( V_162 == 0x4 ) ? 1 : 0 ;
V_171 = V_56 >> V_67 ;
return sprintf ( V_112 , L_70 , V_6 , V_171 ) ;
}
static T_3 F_101 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_112 , T_5 V_22 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 V_6 ;
int V_3 ;
int V_97 ;
int V_162 ;
V_97 = F_87 ( V_112 , 0 , & V_3 ) ;
if ( V_97 )
return V_97 ;
if ( V_3 < 0 || V_3 > 100 )
return - V_117 ;
if ( V_3 == 0 ) {
V_162 = V_155 -> V_86 << V_67 ;
V_6 = V_162 | V_173 ;
} else {
V_162 = V_3 << V_67 ;
V_6 = V_162 | V_174 ;
}
V_97 = F_36 ( V_155 , V_6 ) ;
if ( V_97 < 0 )
return V_97 ;
V_155 -> V_86 = V_6 >> V_67 ;
return V_22 ;
}
static T_3 F_102 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 V_56 ;
int V_97 ;
V_97 = F_37 ( V_155 , & V_56 ) ;
if ( V_97 < 0 )
return V_97 ;
return sprintf ( V_112 , L_64 , V_56 ) ;
}
static T_3 F_103 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_112 , T_5 V_22 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
int V_56 ;
int V_97 ;
V_97 = F_87 ( V_112 , 0 , & V_56 ) ;
if ( V_97 )
return V_97 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_117 ;
V_97 = F_38 ( V_155 , V_56 ) ;
if ( V_97 )
return V_97 ;
return V_22 ;
}
static T_3 F_104 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 V_56 ;
int V_97 ;
V_97 = F_39 ( V_155 , & V_56 ) ;
if ( V_97 < 0 )
return V_97 ;
return sprintf ( V_112 , L_64 , V_56 ) ;
}
static T_3 F_105 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_112 , T_5 V_22 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
int V_56 ;
int V_97 ;
V_97 = F_87 ( V_112 , 0 , & V_56 ) ;
if ( V_97 )
return V_97 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_117 ;
V_97 = F_40 ( V_155 , V_56 ) ;
if ( V_97 )
return V_97 ;
return V_22 ;
}
static T_3 F_106 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
int V_87 ;
int V_97 ;
V_97 = F_41 ( V_155 , & V_87 ) ;
if ( V_97 < 0 )
return V_97 ;
return sprintf ( V_112 , L_64 , V_87 ) ;
}
static T_3 F_107 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_112 , T_5 V_22 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
int V_87 ;
int V_97 ;
V_97 = F_87 ( V_112 , 0 , & V_87 ) ;
if ( V_97 )
return V_97 ;
if ( V_87 != 0 && V_87 != 1 )
return - V_117 ;
V_97 = F_42 ( V_155 , V_87 ) ;
if ( V_97 )
return V_97 ;
F_12 ( L_71 ) ;
return V_22 ;
}
static T_3 F_108 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 V_56 ;
int V_97 ;
V_97 = F_43 ( V_155 , & V_56 ) ;
if ( V_97 < 0 )
return V_97 ;
return sprintf ( V_112 , L_64 , V_56 ) ;
}
static T_3 F_109 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_112 , T_5 V_22 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
int V_56 ;
int V_97 ;
V_97 = F_87 ( V_112 , 0 , & V_56 ) ;
if ( V_97 )
return V_97 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_117 ;
V_97 = F_44 ( V_155 , V_56 ) ;
if ( V_97 )
return V_97 ;
F_12 ( L_72 ) ;
return V_22 ;
}
static T_3 F_110 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_112 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
T_1 V_56 ;
int V_97 ;
V_97 = F_45 ( V_155 , & V_56 ) ;
if ( V_97 < 0 )
return V_97 ;
return sprintf ( V_112 , L_64 , V_56 ) ;
}
static T_3 F_111 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_112 , T_5 V_22 )
{
struct V_9 * V_155 = F_86 ( V_10 ) ;
int V_56 ;
int V_97 ;
V_97 = F_87 ( V_112 , 0 , & V_56 ) ;
if ( V_97 )
return V_97 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_117 ;
V_97 = F_46 ( V_155 , V_56 ) ;
if ( V_97 )
return V_97 ;
F_12 ( L_73 ) ;
return V_22 ;
}
static T_8 F_112 ( struct V_175 * V_176 ,
struct V_177 * V_154 , int V_178 )
{
struct V_152 * V_10 = F_18 ( V_176 , struct V_152 , V_176 ) ;
struct V_9 * V_179 = F_86 ( V_10 ) ;
bool V_180 = true ;
if ( V_154 == & V_181 . V_154 )
V_180 = ( V_179 -> V_147 ) ? true : false ;
else if ( V_154 == & V_182 . V_154 )
V_180 = ( V_179 -> V_60 ) ? true : false ;
else if ( V_154 == & V_183 . V_154 )
V_180 = ( V_179 -> V_64 == V_157 ) ? true : false ;
else if ( V_154 == & V_184 . V_154 )
V_180 = ( V_179 -> V_185 ) ? true : false ;
else if ( V_154 == & V_186 . V_154 )
V_180 = ( V_179 -> V_78 ) ? true : false ;
else if ( V_154 == & V_187 . V_154 )
V_180 = ( V_179 -> V_83 ) ? true : false ;
else if ( V_154 == & V_188 . V_154 )
V_180 = ( V_179 -> V_83 ) ? true : false ;
else if ( V_154 == & V_189 . V_154 )
V_180 = ( V_179 -> V_190 ) ? true : false ;
else if ( V_154 == & V_191 . V_154 )
V_180 = ( V_179 -> V_192 ) ? true : false ;
else if ( V_154 == & V_193 . V_154 )
V_180 = ( V_179 -> V_194 ) ? true : false ;
else if ( V_154 == & V_195 . V_154 )
V_180 = ( V_179 -> V_196 ) ? true : false ;
else if ( V_154 == & V_197 . V_154 )
V_180 = ( V_179 -> V_198 ) ? true : false ;
return V_180 ? V_154 -> V_87 : 0 ;
}
static int F_113 ( T_9 * V_199 )
{
T_1 V_11 [ V_12 ] = { V_199 -> V_200 , V_199 -> V_201 , V_199 -> V_202 ,
V_199 -> V_203 , V_199 -> V_204 , V_199 -> V_205 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_206 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_74 ) ;
return - V_8 ;
}
V_199 -> V_200 = V_13 [ 0 ] ;
V_199 -> V_201 = V_13 [ 1 ] ;
V_199 -> V_202 = V_13 [ 2 ] ;
V_199 -> V_203 = V_13 [ 3 ] ;
V_199 -> V_204 = V_13 [ 4 ] ;
V_199 -> V_205 = V_13 [ 5 ] ;
return 0 ;
}
static long F_114 ( struct V_111 * V_207 , unsigned int V_114 ,
unsigned long V_208 )
{
T_9 T_4 * V_209 = ( T_9 T_4 * ) V_208 ;
T_9 V_199 ;
int V_97 ;
if ( ! V_209 )
return - V_117 ;
switch ( V_114 ) {
case V_210 :
if ( F_63 ( & V_199 , V_209 , sizeof( T_9 ) ) )
return - V_116 ;
V_97 = F_113 ( & V_199 ) ;
if ( V_97 )
return V_97 ;
if ( F_115 ( V_209 , & V_199 , sizeof( T_9 ) ) )
return - V_116 ;
break;
case V_211 :
if ( F_63 ( & V_199 , V_209 , sizeof( T_9 ) ) )
return - V_116 ;
if ( V_199 . V_200 != V_44 && V_199 . V_200 != V_45 )
return - V_117 ;
if ( ! F_10 ( V_206 ) )
return - V_8 ;
V_97 = F_113 ( & V_199 ) ;
F_13 ( V_206 ) ;
if ( V_97 )
return V_97 ;
if ( F_115 ( V_209 , & V_199 , sizeof( T_9 ) ) )
return - V_116 ;
break;
default:
return - V_117 ;
}
return 0 ;
}
static int F_116 ( struct V_9 * V_10 )
{
T_2 V_6 ;
T_1 V_55 ;
V_6 = F_5 ( V_10 -> V_26 -> V_27 ,
L_75 , NULL , NULL ) ;
if ( F_9 ( V_6 ) )
return - V_68 ;
if ( V_10 -> V_194 && V_10 -> V_212 )
V_55 = F_6 ( V_10 , V_213 ,
V_214 ) ;
else
V_55 = F_6 ( V_10 , V_213 , V_215 ) ;
if ( V_55 == V_34 )
return - V_8 ;
else if ( V_55 == V_40 )
return - V_68 ;
return 0 ;
}
static bool F_117 ( unsigned char V_216 , unsigned char V_217 ,
struct V_218 * V_219 )
{
if ( V_217 & V_220 )
return false ;
if ( F_118 ( V_216 == 0xe0 ) )
return false ;
if ( ( V_216 & 0x7f ) == V_221 ) {
F_119 ( & V_206 -> V_222 ) ;
return true ;
}
return false ;
}
static void F_120 ( struct V_223 * V_224 )
{
T_10 V_225 = F_121 () ;
T_2 V_6 ;
if ( ! V_225 )
return;
V_6 = F_5 ( V_225 , L_76 , NULL , NULL ) ;
if ( F_9 ( V_6 ) )
F_11 ( L_77 ) ;
}
static int F_122 ( struct V_9 * V_10 )
{
unsigned long long V_3 ;
T_2 V_6 ;
V_6 = F_123 ( V_10 -> V_26 -> V_27 , L_78 ,
NULL , & V_3 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_79 ) ;
return - V_8 ;
}
return V_3 ;
}
static void F_124 ( struct V_9 * V_10 ,
int V_226 )
{
if ( V_226 == 0x100 )
return;
if ( V_226 & 0x80 )
return;
if ( ! F_125 ( V_10 -> V_149 , V_226 , 1 , true ) )
F_12 ( L_80 , V_226 ) ;
}
static void F_126 ( struct V_9 * V_10 )
{
if ( V_10 -> V_227 ) {
int V_226 = F_122 ( V_10 ) ;
if ( V_226 < 0 ) {
F_11 ( L_81 ) ;
} else if ( V_226 != 0 ) {
F_124 ( V_10 , V_226 ) ;
V_10 -> V_137 = 1 ;
V_10 -> V_138 = V_226 ;
}
} else if ( V_10 -> V_228 ) {
T_1 V_55 ;
T_1 V_3 ;
int V_229 = 3 ;
do {
V_55 = F_8 ( V_10 , V_230 , & V_3 ) ;
switch ( V_55 ) {
case V_49 :
F_124 ( V_10 , ( int ) V_3 ) ;
V_10 -> V_137 = 1 ;
V_10 -> V_138 = V_3 ;
break;
case V_40 :
V_55 = F_6 ( V_10 , V_230 , 1 ) ;
if ( V_55 == V_49 )
F_127 ( L_82 ) ;
default:
V_229 -- ;
break;
}
} while ( V_229 && V_55 != V_231 );
}
}
static int F_128 ( struct V_9 * V_10 )
{
const struct V_232 * V_233 = V_234 ;
T_10 V_225 ;
int error ;
if ( F_129 ( V_235 ) ) {
F_12 ( L_83 ) ;
return 0 ;
}
error = F_116 ( V_10 ) ;
if ( error )
return error ;
if ( F_47 ( V_10 , & V_10 -> V_236 ) )
F_127 ( L_84 ) ;
V_10 -> V_149 = F_130 () ;
if ( ! V_10 -> V_149 )
return - V_132 ;
V_10 -> V_149 -> V_237 = L_85 ;
V_10 -> V_149 -> V_238 = L_86 ;
V_10 -> V_149 -> V_239 . V_240 = V_241 ;
if ( V_10 -> V_236 == V_242 ||
! V_10 -> V_194 )
V_233 = V_234 ;
else if ( V_10 -> V_236 == V_243 ||
V_10 -> V_194 )
V_233 = V_244 ;
else
F_12 ( L_87 ,
V_10 -> V_236 ) ;
error = F_131 ( V_10 -> V_149 , V_233 , NULL ) ;
if ( error )
goto V_245;
V_225 = F_121 () ;
if ( V_225 && F_132 ( V_225 , L_76 ) ) {
F_133 ( & V_10 -> V_222 , F_120 ) ;
error = F_134 ( F_117 ) ;
if ( error ) {
F_11 ( L_88 ) ;
goto V_246;
}
V_10 -> V_247 = 1 ;
}
if ( F_132 ( V_10 -> V_26 -> V_27 , L_78 ) )
V_10 -> V_227 = 1 ;
else if ( F_6 ( V_10 , V_230 , 1 ) == V_49 )
V_10 -> V_228 = 1 ;
if ( ! V_10 -> V_227 && ! V_10 -> V_228 ) {
F_135 ( L_89 ) ;
goto V_248;
}
error = F_136 ( V_10 -> V_149 ) ;
if ( error ) {
F_12 ( L_90 ) ;
goto V_248;
}
return 0 ;
V_248:
if ( V_10 -> V_247 )
F_137 ( F_117 ) ;
V_246:
F_138 ( V_10 -> V_149 ) ;
V_245:
F_139 ( V_10 -> V_149 ) ;
V_10 -> V_149 = NULL ;
return error ;
}
static int F_140 ( struct V_9 * V_10 )
{
struct V_249 V_108 ;
int V_53 ;
int V_97 ;
V_53 = F_50 ( V_10 ) ;
if ( V_53 < 0 )
return 0 ;
V_97 = F_58 ( V_10 , V_53 ) ;
if ( V_97 ) {
F_141 ( L_91 ) ;
return 0 ;
}
if ( V_10 -> V_96 ||
F_142 ( V_250 ) )
F_143 ( V_251 ) ;
if ( F_144 () != V_251 )
return 0 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . type = V_252 ;
V_108 . V_109 = V_253 - 1 ;
if ( V_10 -> V_96 )
V_108 . V_109 ++ ;
V_10 -> V_107 = F_145 ( L_92 ,
& V_10 -> V_26 -> V_10 ,
V_10 ,
& V_254 ,
& V_108 ) ;
if ( F_146 ( V_10 -> V_107 ) ) {
V_97 = F_147 ( V_10 -> V_107 ) ;
F_11 ( L_93 ) ;
V_10 -> V_107 = NULL ;
return V_97 ;
}
V_10 -> V_107 -> V_108 . V_53 = V_53 ;
return 0 ;
}
static void F_148 ( struct V_9 * V_10 )
{
F_12 ( L_94 ) ;
if ( V_10 -> V_149 )
F_149 ( L_95 ) ;
if ( V_10 -> V_107 )
F_149 ( L_96 ) ;
if ( V_10 -> V_145 )
F_149 ( L_97 ) ;
if ( V_10 -> V_147 )
F_149 ( L_98 ) ;
if ( V_10 -> V_96 )
F_149 ( L_99 ) ;
if ( V_10 -> V_47 )
F_149 ( L_100 ) ;
if ( V_10 -> V_60 )
F_149 ( L_101 ) ;
if ( V_10 -> V_185 )
F_149 ( L_102 ) ;
if ( V_10 -> V_73 )
F_149 ( L_103 ) ;
if ( V_10 -> V_78 )
F_149 ( L_104 ) ;
if ( V_10 -> V_83 )
F_149 ( L_105 ) ;
if ( V_10 -> V_190 )
F_149 ( L_106 ) ;
if ( V_10 -> V_192 )
F_149 ( L_107 ) ;
if ( V_10 -> V_194 )
F_149 ( L_108 ) ;
if ( V_10 -> V_196 )
F_149 ( L_109 ) ;
if ( V_10 -> V_198 )
F_149 ( L_110 ) ;
F_149 ( L_111 ) ;
}
static int F_150 ( struct V_255 * V_26 )
{
struct V_9 * V_10 = F_151 ( V_26 ) ;
F_152 ( & V_10 -> V_256 ) ;
F_82 ( V_10 ) ;
if ( V_10 -> V_257 )
F_153 ( & V_10 -> V_26 -> V_10 . V_176 ,
& V_258 ) ;
if ( V_10 -> V_247 ) {
F_137 ( F_117 ) ;
F_154 ( & V_10 -> V_222 ) ;
}
if ( V_10 -> V_149 ) {
F_155 ( V_10 -> V_149 ) ;
F_138 ( V_10 -> V_149 ) ;
}
F_156 ( V_10 -> V_107 ) ;
if ( V_10 -> V_48 )
F_157 ( & V_10 -> V_54 ) ;
if ( V_10 -> V_61 )
F_157 ( & V_10 -> V_69 ) ;
if ( V_10 -> V_74 )
F_157 ( & V_10 -> V_76 ) ;
if ( V_206 )
V_206 = NULL ;
F_69 ( V_10 ) ;
return 0 ;
}
static const char * F_158 ( T_10 V_27 )
{
if ( F_132 ( V_27 , L_112 ) )
return L_112 ;
if ( F_132 ( V_27 , L_113 ) )
return L_113 ;
return NULL ;
}
static int F_159 ( struct V_255 * V_26 )
{
struct V_9 * V_10 ;
const char * V_259 ;
T_1 V_260 ;
int V_97 = 0 ;
if ( V_206 )
return - V_261 ;
F_12 ( L_114 ,
V_139 ) ;
V_259 = F_158 ( V_26 -> V_27 ) ;
if ( ! V_259 ) {
F_11 ( L_115 ) ;
return - V_68 ;
}
V_10 = F_160 ( sizeof( * V_10 ) , V_131 ) ;
if ( ! V_10 )
return - V_132 ;
V_10 -> V_26 = V_26 ;
V_10 -> V_28 = V_259 ;
V_10 -> V_256 . V_262 = V_263 ;
V_10 -> V_256 . V_237 = L_116 ;
V_10 -> V_256 . V_264 = & V_265 ;
V_97 = F_161 ( & V_10 -> V_256 ) ;
if ( V_97 ) {
F_11 ( L_117 ) ;
F_69 ( V_10 ) ;
return V_97 ;
}
V_26 -> V_266 = V_10 ;
F_162 ( & V_26 -> V_10 , V_10 ) ;
V_97 = F_41 ( V_10 , & V_10 -> V_212 ) ;
V_10 -> V_194 = ! V_97 ;
V_10 -> V_236 = 0 ;
if ( F_128 ( V_10 ) )
F_12 ( L_118 ) ;
V_97 = F_48 ( V_10 , & V_260 ) ;
V_10 -> V_96 = ! V_97 ;
V_97 = F_140 ( V_10 ) ;
if ( V_97 )
goto error;
F_16 ( V_10 ) ;
if ( V_10 -> V_47 ) {
V_10 -> V_54 . V_237 = L_119 ;
V_10 -> V_54 . V_109 = 1 ;
V_10 -> V_54 . V_267 = F_17 ;
V_10 -> V_54 . V_268 = F_19 ;
if ( ! F_163 ( & V_26 -> V_10 , & V_10 -> V_54 ) )
V_10 -> V_48 = true ;
}
F_27 ( V_10 ) ;
if ( V_10 -> V_73 ) {
V_10 -> V_76 . V_237 = L_120 ;
V_10 -> V_76 . V_109 = 1 ;
V_10 -> V_76 . V_267 = F_29 ;
V_10 -> V_76 . V_268 = F_28 ;
if ( ! F_163 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_76 ) )
V_10 -> V_74 = true ;
}
F_20 ( V_10 ) ;
if ( V_10 -> V_60 && V_10 -> V_64 == V_156 ) {
V_10 -> V_69 . V_237 = L_121 ;
V_10 -> V_69 . V_109 = 1 ;
V_10 -> V_69 . V_267 = F_24 ;
V_10 -> V_69 . V_268 = F_23 ;
if ( ! F_163 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_69 ) )
V_10 -> V_61 = true ;
}
V_97 = F_26 ( V_10 , & V_260 ) ;
V_10 -> V_185 = ! V_97 ;
F_30 ( V_10 ) ;
F_32 ( V_10 ) ;
V_97 = F_37 ( V_10 , & V_260 ) ;
V_10 -> V_190 = ! V_97 ;
V_97 = F_39 ( V_10 , & V_260 ) ;
V_10 -> V_192 = ! V_97 ;
V_97 = F_43 ( V_10 , & V_260 ) ;
V_10 -> V_196 = ! V_97 ;
V_97 = F_45 ( V_10 , & V_260 ) ;
V_10 -> V_198 = ! V_97 ;
V_97 = F_64 ( V_10 , & V_260 ) ;
V_10 -> V_145 = ! V_97 ;
V_97 = F_70 ( V_10 , & V_260 ) ;
V_10 -> V_147 = ! V_97 ;
F_148 ( V_10 ) ;
V_97 = F_164 ( & V_10 -> V_26 -> V_10 . V_176 ,
& V_258 ) ;
if ( V_97 ) {
V_10 -> V_257 = 0 ;
goto error;
}
V_10 -> V_257 = ! V_97 ;
F_80 ( V_10 ) ;
V_206 = V_10 ;
return 0 ;
error:
F_150 ( V_26 ) ;
return V_97 ;
}
static void F_165 ( struct V_255 * V_26 , T_1 V_269 )
{
struct V_9 * V_10 = F_151 ( V_26 ) ;
int V_97 ;
switch ( V_269 ) {
case 0x80 :
if ( F_129 ( V_235 ) )
return;
F_126 ( V_10 ) ;
break;
case 0x81 :
case 0x82 :
case 0x83 :
F_12 ( L_122 , V_269 ) ;
break;
case 0x88 :
F_12 ( L_123 ) ;
break;
case 0x8f :
case 0x90 :
break;
case 0x8c :
case 0x8b :
F_12 ( L_124 , V_269 ) ;
break;
case 0x92 :
V_97 = F_166 ( & V_26 -> V_10 . V_176 ,
& V_258 ) ;
if ( V_97 )
F_11 ( L_125 ) ;
break;
case 0x85 :
case 0x8d :
case 0x8e :
case 0x94 :
case 0x95 :
default:
F_12 ( L_126 , V_269 ) ;
break;
}
F_167 ( V_26 -> V_270 . V_271 ,
F_168 ( & V_26 -> V_10 ) ,
V_269 , 0 ) ;
}
static int F_169 ( struct V_152 * V_152 )
{
struct V_9 * V_10 = F_151 ( F_170 ( V_152 ) ) ;
if ( V_10 -> V_149 ) {
T_1 V_55 ;
V_55 = F_6 ( V_10 , V_213 , V_272 ) ;
if ( V_55 != V_49 )
F_12 ( L_127 ) ;
}
return 0 ;
}
static int F_171 ( struct V_152 * V_152 )
{
struct V_9 * V_10 = F_151 ( F_170 ( V_152 ) ) ;
if ( V_10 -> V_149 ) {
int error = F_116 ( V_10 ) ;
if ( error )
F_12 ( L_128 ) ;
}
return 0 ;
}
static int T_11 F_172 ( void )
{
int V_97 ;
V_143 = F_173 ( V_273 , V_274 ) ;
if ( ! V_143 ) {
F_11 ( L_129 V_273 L_111 ) ;
return - V_68 ;
}
V_97 = F_174 ( & V_275 ) ;
if ( V_97 ) {
F_11 ( L_130 , V_97 ) ;
F_83 ( V_273 , V_274 ) ;
}
return V_97 ;
}
static void T_12 F_175 ( void )
{
F_176 ( & V_275 ) ;
if ( V_143 )
F_83 ( V_273 , V_274 ) ;
}
