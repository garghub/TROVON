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
static int F_16 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_46 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_6 ) ;
return 0 ;
} else if ( V_13 [ 0 ] == V_40 ) {
F_12 ( L_7 ) ;
return 0 ;
}
return 1 ;
}
static void F_17 ( struct V_47 * V_48 ,
enum V_49 V_50 )
{
struct V_9 * V_10 = F_18 ( V_48 ,
struct V_9 , V_51 ) ;
T_1 V_52 , V_53 ;
if ( ! F_10 ( V_10 ) )
return;
V_52 = V_50 ? 1 : 0 ;
V_53 = F_15 ( V_10 , V_46 , V_52 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 ) {
F_11 ( L_8 ) ;
return;
} else if ( V_53 == V_40 ) {
F_12 ( L_9 ) ;
return;
}
}
static enum V_49 F_19 ( struct V_47 * V_48 )
{
struct V_9 * V_10 = F_18 ( V_48 ,
struct V_9 , V_51 ) ;
T_1 V_52 , V_53 ;
if ( ! F_10 ( V_10 ) )
return V_54 ;
V_53 = F_14 ( V_10 , V_46 , & V_52 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 || V_53 == V_55 ) {
F_11 ( L_8 ) ;
return V_54 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_9 ) ;
return V_54 ;
}
return V_52 ? V_56 : V_54 ;
}
static int F_20 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_57 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_55 ) {
F_11 ( L_10 ) ;
return 0 ;
} else if ( V_13 [ 0 ] == V_40 ) {
F_12 ( L_11 ) ;
return 0 ;
}
if ( V_13 [ 3 ] == V_58 )
V_10 -> V_59 = 2 ;
else
V_10 -> V_59 = 1 ;
V_10 -> V_60 = V_13 [ 2 ] & V_61 ;
V_10 -> V_62 = V_13 [ 2 ] >> V_63 ;
return 1 ;
}
static int F_21 ( struct V_9 * V_10 , T_1 time )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_15 ( V_10 , V_57 , time ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 || V_53 == V_55 ) {
F_11 ( L_12 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_13 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_22 ( struct V_9 * V_10 , T_1 * time )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_14 ( V_10 , V_57 , time ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 || V_53 == V_55 ) {
F_11 ( L_14 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_13 ) ;
return - V_64 ;
}
return 0 ;
}
static enum V_49 F_23 ( struct V_47 * V_48 )
{
struct V_9 * V_10 = F_18 ( V_48 ,
struct V_9 , V_65 ) ;
T_1 V_52 , V_53 ;
V_53 = F_8 ( V_10 , V_66 , & V_52 ) ;
if ( V_53 == V_34 || V_53 == V_55 ) {
F_11 ( L_15 ) ;
return V_54 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_16 ) ;
return V_54 ;
}
return V_52 ? V_56 : V_54 ;
}
static void F_24 ( struct V_47 * V_48 ,
enum V_49 V_50 )
{
struct V_9 * V_10 = F_18 ( V_48 ,
struct V_9 , V_65 ) ;
T_1 V_52 , V_53 ;
V_52 = V_50 ? 1 : 0 ;
V_53 = F_6 ( V_10 , V_66 , V_52 ) ;
if ( V_53 == V_34 || V_53 == V_55 ) {
F_11 ( L_17 ) ;
return;
} else if ( V_53 == V_40 ) {
F_12 ( L_16 ) ;
return;
}
}
static int F_25 ( struct V_9 * V_10 , T_1 V_52 )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_15 ( V_10 , V_67 , V_52 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 ) {
F_11 ( L_18 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
return - V_64 ;
}
return 0 ;
}
static int F_26 ( struct V_9 * V_10 , T_1 * V_52 )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_14 ( V_10 , V_67 , V_52 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 ) {
F_11 ( L_19 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
return - V_64 ;
}
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
T_2 V_6 ;
T_1 V_11 [ V_12 ] = { V_36 , V_68 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_20 ) ;
} else if ( V_13 [ 0 ] == V_69 ) {
F_12 ( L_21 ) ;
} else if ( V_13 [ 0 ] == V_55 ) {
V_11 [ 3 ] = 1 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 )
F_11 ( L_20 ) ;
else if ( V_13 [ 0 ] == V_70 )
return 1 ;
}
return 0 ;
}
static enum V_49
F_28 ( struct V_47 * V_48 )
{
struct V_9 * V_10 = F_18 ( V_48 ,
struct V_9 , V_71 ) ;
T_1 V_11 [ V_12 ] = { V_36 , V_68 , 0 , 1 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_55 ) {
F_11 ( L_20 ) ;
return V_54 ;
}
return V_13 [ 2 ] ? V_56 : V_54 ;
}
static void F_29 ( struct V_47 * V_48 ,
enum V_49 V_50 )
{
struct V_9 * V_10 = F_18 ( V_48 ,
struct V_9 , V_71 ) ;
T_1 V_11 [ V_12 ] = { V_33 , V_68 , 0 , 1 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_11 [ 2 ] = ( V_50 ) ? 1 : 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_55 ) {
F_11 ( L_22 ) ;
return;
}
}
static int F_30 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_72 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_55 ) {
F_11 ( L_23 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_73 ||
V_13 [ 0 ] == V_74 ) {
F_11 ( L_24 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_40 ) {
F_12 ( L_25 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_31 ( struct V_9 * V_10 ,
T_1 * V_75 , T_1 * V_76 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_77 , 0 , 1 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_55 ) {
F_11 ( L_23 ) ;
return - V_8 ;
}
* V_75 = V_13 [ 2 ] ;
* V_76 = V_13 [ 4 ] ;
return 0 ;
}
static void F_32 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_78 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_10 -> V_79 = 0 ;
if ( ! F_10 ( V_10 ) )
return;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_26 ) ;
F_13 ( V_10 ) ;
return;
} else if ( V_13 [ 0 ] == V_40 ) {
F_12 ( L_27 ) ;
F_13 ( V_10 ) ;
return;
} else if ( V_13 [ 0 ] == V_70 ) {
V_10 -> V_80 = V_13 [ 4 ] ;
}
V_11 [ 5 ] = V_81 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_26 ) ;
F_13 ( V_10 ) ;
return;
} else if ( V_13 [ 0 ] == V_40 ) {
F_12 ( L_27 ) ;
F_13 ( V_10 ) ;
return;
} else if ( V_13 [ 0 ] == V_70 ) {
V_10 -> V_82 = V_13 [ 2 ] ;
V_10 -> V_79 = 1 ;
}
F_13 ( V_10 ) ;
}
static int F_33 ( struct V_9 * V_10 ,
T_1 * V_83 )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_14 ( V_10 , V_78 , V_83 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 ) {
F_11 ( L_28 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_27 ) ;
return - V_64 ;
} else if ( V_53 == V_55 ) {
return - V_8 ;
}
return 0 ;
}
static int F_34 ( struct V_9 * V_10 ,
T_1 V_83 )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_15 ( V_10 , V_78 , V_83 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 ) {
F_11 ( L_28 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_27 ) ;
return - V_64 ;
} else if ( V_53 == V_55 ) {
return - V_8 ;
}
return 0 ;
}
static int F_35 ( struct V_9 * V_10 ,
T_1 * V_83 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_78 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_11 [ 5 ] = V_81 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_29 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_40 ) {
F_12 ( L_27 ) ;
return - V_64 ;
} else if ( V_13 [ 0 ] == V_55 ) {
return - V_8 ;
}
* V_83 = V_13 [ 2 ] ;
return 0 ;
}
static int F_36 ( struct V_9 * V_10 ,
T_1 V_83 )
{
T_1 V_11 [ V_12 ] = { V_45 , V_78 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_11 [ 2 ] = V_83 ;
V_11 [ 5 ] = V_81 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_30 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_40 ) {
F_12 ( L_27 ) ;
return - V_64 ;
} else if ( V_13 [ 0 ] == V_55 ) {
return - V_8 ;
}
return 0 ;
}
static int F_37 ( struct V_9 * V_10 ,
T_1 * V_52 )
{
T_1 V_11 [ V_12 ] = { V_44 , V_78 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_11 [ 5 ] = V_84 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_31 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_40 ||
V_13 [ 0 ] == V_55 ) {
F_12 ( L_32 ) ;
return - V_64 ;
}
* V_52 = V_13 [ 2 ] ;
return 0 ;
}
static int F_38 ( struct V_9 * V_10 ,
T_1 V_52 )
{
T_1 V_11 [ V_12 ] = { V_45 , V_78 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_11 [ 2 ] = V_52 ;
V_11 [ 5 ] = V_84 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_13 ( V_10 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_33 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_40 ) {
F_12 ( L_32 ) ;
return - V_64 ;
} else if ( V_13 [ 0 ] == V_55 ) {
return - V_8 ;
}
return 0 ;
}
static int F_39 ( struct V_9 * V_10 , T_1 * V_52 )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_14 ( V_10 , V_85 , V_52 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 ) {
F_11 ( L_34 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_35 ) ;
return - V_64 ;
} else if ( V_53 == V_55 ) {
return - V_8 ;
}
return 0 ;
}
static int F_40 ( struct V_9 * V_10 , T_1 V_52 )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_15 ( V_10 , V_85 , V_52 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 ) {
F_11 ( L_36 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_35 ) ;
return - V_64 ;
} else if ( V_53 == V_55 ) {
return - V_8 ;
}
return 0 ;
}
static int F_41 ( struct V_9 * V_10 , T_1 * V_83 )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_14 ( V_10 , V_86 , V_83 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 || V_53 == V_55 ) {
F_11 ( L_37 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_38 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_42 ( struct V_9 * V_10 , T_1 V_83 )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_15 ( V_10 , V_86 , V_83 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 || V_53 == V_55 ) {
F_11 ( L_39 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_38 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_43 ( struct V_9 * V_10 , T_1 * V_52 )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_14 ( V_10 , V_87 , V_52 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 ) {
F_11 ( L_40 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_41 ) ;
return - V_64 ;
} else if ( V_53 == V_55 ) {
return - V_8 ;
}
return 0 ;
}
static int F_44 ( struct V_9 * V_10 , T_1 V_52 )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_15 ( V_10 , V_87 , V_52 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 ) {
F_11 ( L_42 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_43 ) ;
return - V_64 ;
} else if ( V_53 == V_55 ) {
return - V_8 ;
}
return 0 ;
}
static int F_45 ( struct V_9 * V_10 , T_1 * V_52 )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_14 ( V_10 , V_88 , V_52 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 ) {
F_11 ( L_44 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_45 ) ;
return - V_64 ;
} else if ( V_53 == V_55 ) {
return - V_8 ;
}
return 0 ;
}
static int F_46 ( struct V_9 * V_10 , T_1 V_52 )
{
T_1 V_53 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_53 = F_15 ( V_10 , V_88 , V_52 ) ;
F_13 ( V_10 ) ;
if ( V_53 == V_34 ) {
F_11 ( L_46 ) ;
return - V_8 ;
} else if ( V_53 == V_40 ) {
F_12 ( L_45 ) ;
return - V_64 ;
} else if ( V_53 == V_55 ) {
return - V_8 ;
}
return 0 ;
}
static int F_47 ( struct V_9 * V_10 ,
T_1 * type )
{
T_1 V_11 [ V_12 ] = { V_36 , V_89 , 0x03 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_47 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_40 ) {
F_12 ( L_48 ) ;
return - V_64 ;
}
* type = V_13 [ 3 ] ;
return 0 ;
}
static int F_48 ( struct V_9 * V_10 , bool * V_90 )
{
T_1 V_91 ;
T_1 V_6 ;
V_91 = F_8 ( V_10 , V_92 , & V_6 ) ;
* V_90 = ! V_6 ;
return V_91 == V_70 ? 0 : - V_8 ;
}
static int F_49 ( struct V_9 * V_10 , bool V_93 )
{
T_1 V_91 ;
T_1 V_3 = ! V_93 ;
V_91 = F_6 ( V_10 , V_92 , V_3 ) ;
return V_91 == V_70 ? 0 : - V_8 ;
}
static int F_50 ( struct V_9 * V_10 )
{
T_1 V_91 ;
T_1 V_3 ;
int V_50 = 0 ;
if ( V_10 -> V_94 ) {
bool V_90 ;
int V_95 = F_48 ( V_10 , & V_90 ) ;
if ( V_95 )
return V_95 ;
if ( V_90 )
return 0 ;
V_50 ++ ;
}
V_91 = F_8 ( V_10 , V_96 , & V_3 ) ;
if ( V_91 == V_70 )
return V_50 + ( V_3 >> V_97 ) ;
return - V_8 ;
}
static int F_51 ( struct V_98 * V_99 )
{
struct V_9 * V_10 = F_52 ( V_99 ) ;
return F_50 ( V_10 ) ;
}
static int F_53 ( struct V_100 * V_101 , void * V_102 )
{
struct V_9 * V_10 = V_101 -> V_103 ;
int V_3 ;
int V_104 ;
if ( ! V_10 -> V_105 )
return - V_64 ;
V_104 = V_10 -> V_105 -> V_106 . V_107 + 1 ;
V_3 = F_51 ( V_10 -> V_105 ) ;
if ( V_3 >= 0 ) {
F_54 ( V_101 , L_49 , V_3 ) ;
F_54 ( V_101 , L_50 , V_104 ) ;
return 0 ;
}
F_11 ( L_51 ) ;
return - V_8 ;
}
static int F_55 ( struct V_108 * V_108 , struct V_109 * V_109 )
{
return F_56 ( V_109 , F_53 , F_57 ( V_108 ) ) ;
}
static int F_58 ( struct V_9 * V_10 , int V_3 )
{
T_1 V_91 ;
if ( V_10 -> V_94 ) {
bool V_93 = ! V_3 ;
int V_95 = F_49 ( V_10 , V_93 ) ;
if ( V_95 )
return V_95 ;
if ( V_3 )
V_3 -- ;
}
V_3 = V_3 << V_97 ;
V_91 = F_6 ( V_10 , V_96 , V_3 ) ;
return V_91 == V_70 ? 0 : - V_8 ;
}
static int F_59 ( struct V_98 * V_99 )
{
struct V_9 * V_10 = F_52 ( V_99 ) ;
return F_58 ( V_10 , V_99 -> V_106 . V_50 ) ;
}
static T_3 F_60 ( struct V_109 * V_109 , const char T_4 * V_110 ,
T_5 V_22 , T_6 * V_111 )
{
struct V_9 * V_10 = F_57 ( F_61 ( V_109 ) ) ;
char V_112 [ 42 ] ;
T_5 V_113 ;
int V_3 ;
int V_95 ;
int V_104 = V_10 -> V_105 -> V_106 . V_107 + 1 ;
V_113 = F_62 ( V_22 , sizeof( V_112 ) - 1 ) ;
if ( F_63 ( V_112 , V_110 , V_113 ) )
return - V_114 ;
V_112 [ V_113 ] = '\0' ;
if ( sscanf ( V_112 , L_52 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 < V_104 ) {
V_95 = F_58 ( V_10 , V_3 ) ;
if ( V_95 == 0 )
V_95 = V_22 ;
} else {
V_95 = - V_115 ;
}
return V_95 ;
}
static int F_64 ( struct V_9 * V_10 , T_1 * V_6 )
{
T_1 V_91 ;
V_91 = F_8 ( V_10 , V_116 , V_6 ) ;
return V_91 == V_70 ? 0 : - V_8 ;
}
static int F_65 ( struct V_100 * V_101 , void * V_102 )
{
struct V_9 * V_10 = V_101 -> V_103 ;
T_1 V_3 ;
int V_95 ;
V_95 = F_64 ( V_10 , & V_3 ) ;
if ( ! V_95 ) {
int V_117 = ( V_3 & V_118 ) ? 1 : 0 ;
int V_119 = ( V_3 & V_120 ) ? 1 : 0 ;
int V_121 = ( V_3 & V_122 ) ? 1 : 0 ;
F_54 ( V_101 , L_53 , V_117 ) ;
F_54 ( V_101 , L_54 , V_119 ) ;
F_54 ( V_101 , L_55 , V_121 ) ;
}
return V_95 ;
}
static int F_66 ( struct V_108 * V_108 , struct V_109 * V_109 )
{
return F_56 ( V_109 , F_65 , F_57 ( V_108 ) ) ;
}
static T_3 F_67 ( struct V_109 * V_109 , const char T_4 * V_110 ,
T_5 V_22 , T_6 * V_111 )
{
struct V_9 * V_10 = F_57 ( F_61 ( V_109 ) ) ;
char * V_112 , * V_123 ;
int V_95 ;
int V_3 ;
int V_124 = V_22 ;
int V_125 = - 1 ;
int V_126 = - 1 ;
int V_127 = - 1 ;
T_1 V_128 ;
V_112 = F_68 ( V_22 + 1 , V_129 ) ;
if ( ! V_112 )
return - V_130 ;
if ( F_63 ( V_112 , V_110 , V_22 ) ) {
F_69 ( V_112 ) ;
return - V_114 ;
}
V_112 [ V_22 ] = '\0' ;
V_123 = V_112 ;
while ( V_124 ) {
if ( sscanf ( V_123 , L_56 , & V_3 ) == 1 )
V_125 = V_3 & 1 ;
else if ( sscanf ( V_123 , L_57 , & V_3 ) == 1 )
V_126 = V_3 & 1 ;
else if ( sscanf ( V_123 , L_58 , & V_3 ) == 1 )
V_127 = V_3 & 1 ;
do {
++ V_123 ;
-- V_124 ;
} while ( V_124 && * ( V_123 - 1 ) != ';' );
}
F_69 ( V_112 ) ;
V_95 = F_64 ( V_10 , & V_128 ) ;
if ( ! V_95 ) {
unsigned int V_131 = V_128 ;
if ( V_125 != - 1 )
F_1 ( & V_131 , V_118 , V_125 ) ;
if ( V_126 != - 1 )
F_1 ( & V_131 , V_120 , V_126 ) ;
if ( V_127 != - 1 )
F_1 ( & V_131 , V_122 , V_127 ) ;
if ( V_131 != V_128 )
V_95 = F_2 ( V_132 , V_131 ) ;
}
return V_95 ? V_95 : V_22 ;
}
static int F_70 ( struct V_9 * V_10 , T_1 * V_6 )
{
T_1 V_91 ;
V_91 = F_8 ( V_10 , V_133 , V_6 ) ;
return V_91 == V_70 ? 0 : - V_8 ;
}
static int F_71 ( struct V_100 * V_101 , void * V_102 )
{
struct V_9 * V_10 = V_101 -> V_103 ;
int V_95 ;
T_1 V_3 ;
V_95 = F_70 ( V_10 , & V_3 ) ;
if ( ! V_95 ) {
F_54 ( V_101 , L_59 , ( V_3 > 0 ) ) ;
F_54 ( V_101 , L_60 , V_10 -> V_134 ) ;
}
return V_95 ;
}
static int F_72 ( struct V_108 * V_108 , struct V_109 * V_109 )
{
return F_56 ( V_109 , F_71 , F_57 ( V_108 ) ) ;
}
static T_3 F_73 ( struct V_109 * V_109 , const char T_4 * V_110 ,
T_5 V_22 , T_6 * V_111 )
{
struct V_9 * V_10 = F_57 ( F_61 ( V_109 ) ) ;
char V_112 [ 42 ] ;
T_5 V_113 ;
int V_3 ;
T_1 V_91 ;
V_113 = F_62 ( V_22 , sizeof( V_112 ) - 1 ) ;
if ( F_63 ( V_112 , V_110 , V_113 ) )
return - V_114 ;
V_112 [ V_113 ] = '\0' ;
if ( sscanf ( V_112 , L_61 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 <= 1 ) {
V_91 = F_6 ( V_10 , V_133 , V_3 ) ;
if ( V_91 == V_70 )
V_10 -> V_134 = V_3 ;
else
return - V_8 ;
} else {
return - V_115 ;
}
return V_22 ;
}
static int F_74 ( struct V_100 * V_101 , void * V_102 )
{
struct V_9 * V_10 = V_101 -> V_103 ;
T_1 V_91 ;
T_1 V_3 ;
if ( ! V_10 -> V_135 && V_10 -> V_136 ) {
V_91 = F_8 ( V_10 , V_137 , & V_3 ) ;
if ( V_91 == V_70 ) {
V_10 -> V_135 = 1 ;
V_10 -> V_138 = V_3 ;
} else if ( V_91 == V_139 ) {
} else if ( V_91 == V_40 ) {
V_91 = F_6 ( V_10 , V_137 , 1 ) ;
F_75 ( L_62 ) ;
} else {
F_11 ( L_63 ) ;
return - V_8 ;
}
}
F_54 ( V_101 , L_64 , V_10 -> V_135 ) ;
F_54 ( V_101 , L_65 , V_10 -> V_138 ) ;
return 0 ;
}
static int F_76 ( struct V_108 * V_108 , struct V_109 * V_109 )
{
return F_56 ( V_109 , F_74 , F_57 ( V_108 ) ) ;
}
static T_3 F_77 ( struct V_109 * V_109 , const char T_4 * V_110 ,
T_5 V_22 , T_6 * V_111 )
{
struct V_9 * V_10 = F_57 ( F_61 ( V_109 ) ) ;
char V_112 [ 42 ] ;
T_5 V_113 ;
int V_3 ;
V_113 = F_62 ( V_22 , sizeof( V_112 ) - 1 ) ;
if ( F_63 ( V_112 , V_110 , V_113 ) )
return - V_114 ;
V_112 [ V_113 ] = '\0' ;
if ( sscanf ( V_112 , L_66 , & V_3 ) == 1 && V_3 == 0 )
V_10 -> V_135 = 0 ;
else
return - V_115 ;
return V_22 ;
}
static int F_78 ( struct V_100 * V_101 , void * V_102 )
{
F_54 ( V_101 , L_67 , V_140 ) ;
F_54 ( V_101 , L_68 , V_141 ) ;
return 0 ;
}
static int F_79 ( struct V_108 * V_108 , struct V_109 * V_109 )
{
return F_56 ( V_109 , F_78 , F_57 ( V_108 ) ) ;
}
static void F_80 ( struct V_9 * V_10 )
{
if ( V_10 -> V_105 )
F_81 ( L_69 , V_142 | V_143 , V_144 ,
& V_145 , V_10 ) ;
if ( V_10 -> V_146 )
F_81 ( L_70 , V_142 | V_143 , V_144 ,
& V_147 , V_10 ) ;
if ( V_10 -> V_148 )
F_81 ( L_71 , V_142 | V_143 , V_144 ,
& V_149 , V_10 ) ;
if ( V_10 -> V_150 )
F_81 ( L_72 , V_142 | V_143 , V_144 ,
& V_151 , V_10 ) ;
F_81 ( L_73 , V_142 , V_144 ,
& V_152 , V_10 ) ;
}
static void F_82 ( struct V_9 * V_10 )
{
if ( V_10 -> V_105 )
F_83 ( L_69 , V_144 ) ;
if ( V_10 -> V_146 )
F_83 ( L_70 , V_144 ) ;
if ( V_10 -> V_148 )
F_83 ( L_71 , V_144 ) ;
if ( V_10 -> V_150 )
F_83 ( L_72 , V_144 ) ;
F_83 ( L_73 , V_144 ) ;
}
static T_3 F_84 ( struct V_153 * V_10 ,
struct V_154 * V_155 , char * V_110 )
{
return sprintf ( V_110 , L_74 , V_140 ) ;
}
static T_3 F_85 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
const char * V_110 , T_5 V_22 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 V_53 ;
int V_52 ;
int V_95 ;
V_95 = F_87 ( V_110 , 0 , & V_52 ) ;
if ( V_95 )
return V_95 ;
if ( V_52 != 0 && V_52 != 1 )
return - V_115 ;
V_53 = F_6 ( V_156 , V_133 , V_52 ) ;
if ( V_53 == V_34 )
return - V_8 ;
else if ( V_53 == V_40 )
return - V_64 ;
return V_22 ;
}
static T_3 F_88 ( struct V_153 * V_10 ,
struct V_154 * V_155 , char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 V_3 ;
int V_95 ;
V_95 = F_70 ( V_156 , & V_3 ) ;
if ( V_95 )
return V_95 ;
return sprintf ( V_110 , L_75 , V_3 ) ;
}
static T_3 F_89 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
const char * V_110 , T_5 V_22 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
int V_83 ;
int time ;
int V_95 ;
V_95 = F_87 ( V_110 , 0 , & V_83 ) ;
if ( V_95 )
return V_95 ;
if ( V_156 -> V_59 == 1 ) {
if ( V_83 != V_157 && V_83 != V_158 )
return - V_115 ;
} else if ( V_156 -> V_59 == 2 ) {
if ( V_83 != V_158 && V_83 != V_159 &&
V_83 != V_160 )
return - V_115 ;
}
if ( V_156 -> V_60 != V_83 ) {
time = V_156 -> V_62 << V_63 ;
if ( V_156 -> V_59 == 1 ) {
time |= V_156 -> V_60 ;
} else if ( V_156 -> V_59 == 2 ) {
time |= V_83 ;
}
V_95 = F_21 ( V_156 , time ) ;
if ( V_95 )
return V_95 ;
V_156 -> V_60 = V_83 ;
}
return V_22 ;
}
static T_3 F_90 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 time ;
if ( F_22 ( V_156 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_110 , L_76 , time & V_61 ) ;
}
static T_3 F_91 ( struct V_153 * V_10 ,
struct V_154 * V_155 , char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
return sprintf ( V_110 , L_75 , V_156 -> V_59 ) ;
}
static T_3 F_92 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
if ( V_156 -> V_59 == 1 )
return sprintf ( V_110 , L_77 ,
V_157 , V_158 ) ;
return sprintf ( V_110 , L_78 ,
V_158 , V_159 , V_160 ) ;
}
static T_3 F_93 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
const char * V_110 , T_5 V_22 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
int time ;
int V_95 ;
V_95 = F_87 ( V_110 , 0 , & time ) ;
if ( V_95 )
return V_95 ;
if ( V_156 -> V_59 == 1 ) {
if ( time < 0 || time > 60 )
return - V_115 ;
} else if ( V_156 -> V_59 == 2 ) {
if ( time < 1 || time > 60 )
return - V_115 ;
}
if ( V_156 -> V_62 != time ) {
time = time << V_63 ;
if ( V_156 -> V_59 == 1 )
time |= V_157 ;
else if ( V_156 -> V_59 == 2 )
time |= V_158 ;
V_95 = F_21 ( V_156 , time ) ;
if ( V_95 )
return V_95 ;
V_156 -> V_62 = time >> V_63 ;
}
return V_22 ;
}
static T_3 F_94 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 time ;
if ( F_22 ( V_156 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_110 , L_76 , time >> V_63 ) ;
}
static T_3 F_95 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
const char * V_110 , T_5 V_22 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
int V_52 ;
int V_95 ;
V_95 = F_87 ( V_110 , 0 , & V_52 ) ;
if ( V_95 )
return V_95 ;
if ( V_52 != 0 && V_52 != 1 )
return - V_115 ;
V_95 = F_25 ( V_156 , V_52 ) ;
if ( V_95 )
return V_95 ;
return V_22 ;
}
static T_3 F_96 ( struct V_153 * V_10 ,
struct V_154 * V_155 , char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 V_52 ;
int V_95 ;
V_95 = F_26 ( V_156 , & V_52 ) ;
if ( V_95 < 0 )
return V_95 ;
return sprintf ( V_110 , L_76 , V_52 ) ;
}
static T_3 F_97 ( struct V_153 * V_10 ,
struct V_154 * V_155 , char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 V_161 , V_162 , V_163 ;
T_7 V_164 , V_165 , V_76 ;
int V_95 ;
V_161 = V_162 = 0 ;
V_95 = F_31 ( V_156 , & V_161 , & V_162 ) ;
if ( V_95 < 0 )
return V_95 ;
V_164 = V_161 & V_166 ;
V_163 = V_161 >> V_63 ;
V_165 = V_163 & V_166 ;
V_76 = V_162 & V_166 ;
return sprintf ( V_110 , L_79 , V_164 , V_165 , V_76 ) ;
}
static T_3 F_98 ( struct V_153 * V_10 ,
struct V_154 * V_155 , char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 V_83 ;
int V_95 ;
V_95 = F_33 ( V_156 , & V_83 ) ;
if ( V_95 < 0 )
return V_95 ;
return sprintf ( V_110 , L_80 , V_83 & V_167 ) ;
}
static T_3 F_99 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
const char * V_110 , T_5 V_22 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 V_83 ;
int V_52 ;
int V_95 ;
V_95 = F_87 ( V_110 , 0 , & V_52 ) ;
if ( V_95 )
return V_95 ;
if ( V_52 != 0 && V_52 != 1 && V_52 != 2 && V_52 != 3 )
return - V_115 ;
V_83 = V_156 -> V_80 ;
if ( V_52 == 0 )
V_83 |= V_168 ;
else if ( V_52 == 1 )
V_83 |= V_169 ;
else if ( V_52 == 2 )
V_83 |= V_170 ;
else if ( V_52 == 3 )
V_83 |= V_171 ;
V_95 = F_34 ( V_156 , V_83 ) ;
if ( V_95 )
return V_95 ;
return V_22 ;
}
static T_3 F_100 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 V_52 ;
int V_172 ;
int V_6 ;
int V_95 ;
int V_163 ;
V_95 = F_35 ( V_156 , & V_52 ) ;
if ( V_95 < 0 )
return V_95 ;
V_163 = V_52 & V_173 ;
V_6 = ( V_163 == 0x4 ) ? 1 : 0 ;
V_172 = V_52 >> V_63 ;
return sprintf ( V_110 , L_81 , V_6 , V_172 ) ;
}
static T_3 F_101 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
const char * V_110 , T_5 V_22 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 V_6 ;
int V_3 ;
int V_95 ;
int V_163 ;
V_95 = F_87 ( V_110 , 0 , & V_3 ) ;
if ( V_95 )
return V_95 ;
if ( V_3 < 0 || V_3 > 100 )
return - V_115 ;
if ( V_3 == 0 ) {
V_163 = V_156 -> V_82 << V_63 ;
V_6 = V_163 | V_174 ;
} else {
V_163 = V_3 << V_63 ;
V_6 = V_163 | V_175 ;
}
V_95 = F_36 ( V_156 , V_6 ) ;
if ( V_95 < 0 )
return V_95 ;
V_156 -> V_82 = V_6 >> V_63 ;
return V_22 ;
}
static T_3 F_102 ( struct V_153 * V_10 ,
struct V_154 * V_155 , char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 V_52 ;
int V_95 ;
V_95 = F_37 ( V_156 , & V_52 ) ;
if ( V_95 < 0 )
return V_95 ;
return sprintf ( V_110 , L_75 , V_52 ) ;
}
static T_3 F_103 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
const char * V_110 , T_5 V_22 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
int V_52 ;
int V_95 ;
V_95 = F_87 ( V_110 , 0 , & V_52 ) ;
if ( V_95 )
return V_95 ;
if ( V_52 != 0 && V_52 != 1 )
return - V_115 ;
V_95 = F_38 ( V_156 , V_52 ) ;
if ( V_95 )
return V_95 ;
return V_22 ;
}
static T_3 F_104 ( struct V_153 * V_10 ,
struct V_154 * V_155 , char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 V_52 ;
int V_95 ;
V_95 = F_39 ( V_156 , & V_52 ) ;
if ( V_95 < 0 )
return V_95 ;
return sprintf ( V_110 , L_75 , V_52 ) ;
}
static T_3 F_105 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
const char * V_110 , T_5 V_22 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
int V_52 ;
int V_95 ;
V_95 = F_87 ( V_110 , 0 , & V_52 ) ;
if ( V_95 )
return V_95 ;
if ( V_52 != 0 && V_52 != 1 )
return - V_115 ;
V_95 = F_40 ( V_156 , V_52 ) ;
if ( V_95 )
return V_95 ;
return V_22 ;
}
static T_3 F_106 ( struct V_153 * V_10 ,
struct V_154 * V_155 , char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
int V_83 ;
int V_95 ;
V_95 = F_41 ( V_156 , & V_83 ) ;
if ( V_95 < 0 )
return V_95 ;
return sprintf ( V_110 , L_75 , V_83 ) ;
}
static T_3 F_107 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
const char * V_110 , T_5 V_22 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
int V_83 ;
int V_95 ;
V_95 = F_87 ( V_110 , 0 , & V_83 ) ;
if ( V_95 )
return V_95 ;
if ( V_83 != 0 && V_83 != 1 )
return - V_115 ;
V_95 = F_42 ( V_156 , V_83 ) ;
if ( V_95 )
return V_95 ;
F_12 ( L_82 ) ;
return V_22 ;
}
static T_3 F_108 ( struct V_153 * V_10 ,
struct V_154 * V_155 , char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 V_52 ;
int V_95 ;
V_95 = F_43 ( V_156 , & V_52 ) ;
if ( V_95 < 0 )
return V_95 ;
return sprintf ( V_110 , L_75 , V_52 ) ;
}
static T_3 F_109 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
const char * V_110 , T_5 V_22 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
int V_52 ;
int V_95 ;
V_95 = F_87 ( V_110 , 0 , & V_52 ) ;
if ( V_95 )
return V_95 ;
if ( V_52 != 0 && V_52 != 1 )
return - V_115 ;
V_95 = F_44 ( V_156 , V_52 ) ;
if ( V_95 )
return V_95 ;
F_12 ( L_83 ) ;
return V_22 ;
}
static T_3 F_110 ( struct V_153 * V_10 ,
struct V_154 * V_155 , char * V_110 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
T_1 V_52 ;
int V_95 ;
V_95 = F_45 ( V_156 , & V_52 ) ;
if ( V_95 < 0 )
return V_95 ;
return sprintf ( V_110 , L_75 , V_52 ) ;
}
static T_3 F_111 ( struct V_153 * V_10 ,
struct V_154 * V_155 ,
const char * V_110 , T_5 V_22 )
{
struct V_9 * V_156 = F_86 ( V_10 ) ;
int V_52 ;
int V_95 ;
V_95 = F_87 ( V_110 , 0 , & V_52 ) ;
if ( V_95 )
return V_95 ;
if ( V_52 != 0 && V_52 != 1 )
return - V_115 ;
V_95 = F_46 ( V_156 , V_52 ) ;
if ( V_95 )
return V_95 ;
F_12 ( L_84 ) ;
return V_22 ;
}
static T_8 F_112 ( struct V_176 * V_177 ,
struct V_178 * V_155 , int V_179 )
{
struct V_153 * V_10 = F_18 ( V_177 , struct V_153 , V_177 ) ;
struct V_9 * V_180 = F_86 ( V_10 ) ;
bool V_181 = true ;
if ( V_155 == & V_182 . V_155 )
V_181 = ( V_180 -> V_148 ) ? true : false ;
else if ( V_155 == & V_183 . V_155 )
V_181 = ( V_180 -> V_184 ) ? true : false ;
else if ( V_155 == & V_185 . V_155 )
V_181 = ( V_180 -> V_60 == V_158 ) ? true : false ;
else if ( V_155 == & V_186 . V_155 )
V_181 = ( V_180 -> V_187 ) ? true : false ;
else if ( V_155 == & V_188 . V_155 )
V_181 = ( V_180 -> V_189 ) ? true : false ;
else if ( V_155 == & V_190 . V_155 )
V_181 = ( V_180 -> V_79 ) ? true : false ;
else if ( V_155 == & V_191 . V_155 )
V_181 = ( V_180 -> V_79 ) ? true : false ;
else if ( V_155 == & V_192 . V_155 )
V_181 = ( V_180 -> V_193 ) ? true : false ;
else if ( V_155 == & V_194 . V_155 )
V_181 = ( V_180 -> V_195 ) ? true : false ;
else if ( V_155 == & V_196 . V_155 )
V_181 = ( V_180 -> V_197 ) ? true : false ;
else if ( V_155 == & V_198 . V_155 )
V_181 = ( V_180 -> V_199 ) ? true : false ;
else if ( V_155 == & V_200 . V_155 )
V_181 = ( V_180 -> V_201 ) ? true : false ;
return V_181 ? V_155 -> V_83 : 0 ;
}
static int F_113 ( struct V_9 * V_10 )
{
T_2 V_6 ;
T_1 V_53 ;
V_6 = F_5 ( V_10 -> V_26 -> V_27 ,
L_85 , NULL , NULL ) ;
if ( F_9 ( V_6 ) )
return - V_64 ;
V_53 = F_6 ( V_10 , V_202 , V_203 ) ;
if ( V_53 == V_34 )
return - V_8 ;
else if ( V_53 == V_40 )
return - V_64 ;
return 0 ;
}
static void F_114 ( struct V_9 * V_10 )
{
T_1 V_53 ;
V_53 = F_6 ( V_10 , V_202 ,
V_204 ) ;
if ( V_53 != V_70 )
F_11 ( L_86 ) ;
}
static bool F_115 ( unsigned char V_205 , unsigned char V_206 ,
struct V_207 * V_208 )
{
if ( V_206 & V_209 )
return false ;
if ( F_116 ( V_205 == 0xe0 ) )
return false ;
if ( ( V_205 & 0x7f ) == V_210 ) {
F_117 ( & V_211 -> V_212 ) ;
return true ;
}
return false ;
}
static void F_118 ( struct V_213 * V_214 )
{
T_9 V_215 = F_119 () ;
T_2 V_6 ;
if ( ! V_215 )
return;
V_6 = F_5 ( V_215 , L_87 , NULL , NULL ) ;
if ( F_9 ( V_6 ) )
F_11 ( L_88 ) ;
}
static int F_120 ( struct V_9 * V_10 )
{
unsigned long long V_3 ;
T_2 V_6 ;
V_6 = F_121 ( V_10 -> V_26 -> V_27 , L_89 ,
NULL , & V_3 ) ;
if ( F_9 ( V_6 ) ) {
F_11 ( L_90 ) ;
return - V_8 ;
}
return V_3 ;
}
static void F_122 ( struct V_9 * V_10 ,
int V_216 )
{
if ( V_216 == 0x100 )
return;
if ( V_216 & 0x80 )
return;
if ( ! F_123 ( V_10 -> V_150 , V_216 , 1 , true ) )
F_12 ( L_91 , V_216 ) ;
}
static void F_124 ( struct V_9 * V_10 )
{
T_1 V_91 , V_3 ;
int V_217 = 3 ;
int V_216 ;
if ( V_10 -> V_218 ) {
V_216 = F_120 ( V_10 ) ;
if ( V_216 < 0 )
F_11 ( L_92 ) ;
else if ( V_216 != 0 )
F_122 ( V_10 , V_216 ) ;
} else if ( V_10 -> V_136 ) {
do {
V_91 = F_8 ( V_10 , V_137 , & V_3 ) ;
switch ( V_91 ) {
case V_70 :
F_122 ( V_10 , ( int ) V_3 ) ;
break;
case V_40 :
V_91 =
F_6 ( V_10 , V_137 , 1 ) ;
F_75 ( L_62 ) ;
default:
V_217 -- ;
break;
}
} while ( V_217 && V_91 != V_139 );
}
}
static int F_125 ( struct V_9 * V_10 )
{
const struct V_219 * V_220 = V_221 ;
T_9 V_215 ;
T_1 V_222 ;
T_1 V_91 ;
int error ;
error = F_113 ( V_10 ) ;
if ( error )
return error ;
error = F_47 ( V_10 , & V_222 ) ;
if ( error ) {
F_11 ( L_93 ) ;
return error ;
}
V_10 -> V_223 = V_222 ;
V_10 -> V_150 = F_126 () ;
if ( ! V_10 -> V_150 )
return - V_130 ;
V_10 -> V_150 -> V_224 = L_94 ;
V_10 -> V_150 -> V_225 = L_95 ;
V_10 -> V_150 -> V_226 . V_227 = V_228 ;
if ( V_222 == V_229 ||
! V_10 -> V_197 )
V_220 = V_221 ;
else if ( V_222 == V_230 ||
V_10 -> V_197 )
V_220 = V_231 ;
else
F_12 ( L_96 , V_222 ) ;
error = F_127 ( V_10 -> V_150 , V_220 , NULL ) ;
if ( error )
goto V_232;
V_215 = F_119 () ;
if ( V_215 && F_128 ( V_215 , L_87 ) ) {
F_129 ( & V_10 -> V_212 , F_118 ) ;
error = F_130 ( F_115 ) ;
if ( error ) {
F_11 ( L_97 ) ;
goto V_233;
}
V_10 -> V_234 = 1 ;
}
if ( F_128 ( V_10 -> V_26 -> V_27 , L_89 ) )
V_10 -> V_218 = 1 ;
else {
V_91 = F_6 ( V_10 , V_137 , 1 ) ;
if ( V_91 == V_70 )
V_10 -> V_136 = 1 ;
}
if ( ! V_10 -> V_218 && ! V_10 -> V_136 ) {
F_131 ( L_98 ) ;
goto V_235;
}
error = F_132 ( V_10 -> V_150 ) ;
if ( error ) {
F_12 ( L_99 ) ;
goto V_235;
}
return 0 ;
V_235:
if ( V_10 -> V_234 )
F_133 ( F_115 ) ;
V_233:
F_134 ( V_10 -> V_150 ) ;
V_232:
F_135 ( V_10 -> V_150 ) ;
V_10 -> V_150 = NULL ;
return error ;
}
static int F_136 ( struct V_9 * V_10 )
{
struct V_236 V_106 ;
int V_50 ;
int V_95 ;
bool V_90 ;
V_50 = F_50 ( V_10 ) ;
if ( V_50 < 0 )
return 0 ;
V_95 = F_58 ( V_10 , V_50 ) ;
if ( V_95 ) {
F_137 ( L_100 ) ;
return 0 ;
}
V_95 = F_48 ( V_10 , & V_90 ) ;
V_10 -> V_94 = ! V_95 ;
if ( V_10 -> V_94 ||
F_138 ( V_237 ) )
F_139 ( V_238 ) ;
if ( F_140 () != V_238 )
return 0 ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . type = V_239 ;
V_106 . V_107 = V_240 - 1 ;
if ( V_10 -> V_94 )
V_106 . V_107 ++ ;
V_10 -> V_105 = F_141 ( L_101 ,
& V_10 -> V_26 -> V_10 ,
V_10 ,
& V_241 ,
& V_106 ) ;
if ( F_142 ( V_10 -> V_105 ) ) {
V_95 = F_143 ( V_10 -> V_105 ) ;
F_11 ( L_102 ) ;
V_10 -> V_105 = NULL ;
return V_95 ;
}
V_10 -> V_105 -> V_106 . V_50 = V_50 ;
return 0 ;
}
static int F_144 ( struct V_242 * V_26 )
{
struct V_9 * V_10 = F_145 ( V_26 ) ;
F_82 ( V_10 ) ;
if ( V_10 -> V_243 )
F_146 ( & V_10 -> V_26 -> V_10 . V_177 ,
& V_244 ) ;
if ( V_10 -> V_234 ) {
F_133 ( F_115 ) ;
F_147 ( & V_10 -> V_212 ) ;
}
if ( V_10 -> V_150 ) {
F_148 ( V_10 -> V_150 ) ;
F_134 ( V_10 -> V_150 ) ;
}
F_149 ( V_10 -> V_105 ) ;
if ( V_10 -> V_245 )
F_150 ( & V_10 -> V_51 ) ;
if ( V_10 -> V_246 )
F_150 ( & V_10 -> V_65 ) ;
if ( V_10 -> V_247 )
F_150 ( & V_10 -> V_71 ) ;
if ( V_211 )
V_211 = NULL ;
F_69 ( V_10 ) ;
return 0 ;
}
static const char * F_151 ( T_9 V_27 )
{
if ( F_128 ( V_27 , L_103 ) )
return L_103 ;
if ( F_128 ( V_27 , L_104 ) )
return L_104 ;
return NULL ;
}
static int F_152 ( struct V_242 * V_26 )
{
struct V_9 * V_10 ;
const char * V_248 ;
T_1 V_249 ;
T_1 V_250 ;
int V_95 = 0 ;
if ( V_211 )
return - V_251 ;
F_12 ( L_105 ,
V_140 ) ;
V_248 = F_151 ( V_26 -> V_27 ) ;
if ( ! V_248 ) {
F_11 ( L_106 ) ;
return - V_64 ;
}
V_10 = F_153 ( sizeof( * V_10 ) , V_129 ) ;
if ( ! V_10 )
return - V_130 ;
V_10 -> V_26 = V_26 ;
V_10 -> V_28 = V_248 ;
V_26 -> V_252 = V_10 ;
F_154 ( & V_26 -> V_10 , V_10 ) ;
V_95 = F_41 ( V_10 , & V_249 ) ;
V_10 -> V_197 = ! V_95 ;
if ( F_125 ( V_10 ) )
F_12 ( L_107 ) ;
V_95 = F_136 ( V_10 ) ;
if ( V_95 )
goto error;
if ( F_16 ( V_10 ) ) {
V_10 -> V_51 . V_224 = L_108 ;
V_10 -> V_51 . V_107 = 1 ;
V_10 -> V_51 . V_253 = F_17 ;
V_10 -> V_51 . V_254 = F_19 ;
if ( ! F_155 ( & V_26 -> V_10 , & V_10 -> V_51 ) )
V_10 -> V_245 = 1 ;
}
if ( F_27 ( V_10 ) ) {
V_10 -> V_71 . V_224 = L_109 ;
V_10 -> V_71 . V_107 = 1 ;
V_10 -> V_71 . V_253 = F_29 ;
V_10 -> V_71 . V_254 = F_28 ;
if ( ! F_155 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_71 ) )
V_10 -> V_247 = 1 ;
}
V_10 -> V_184 = F_20 ( V_10 ) ;
if ( V_10 -> V_184 && V_10 -> V_60 == V_157 ) {
V_10 -> V_65 . V_224 = L_110 ;
V_10 -> V_65 . V_107 = 1 ;
V_10 -> V_65 . V_253 = F_24 ;
V_10 -> V_65 . V_254 = F_23 ;
if ( ! F_155 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_65 ) )
V_10 -> V_246 = 1 ;
}
V_95 = F_26 ( V_10 , & V_250 ) ;
V_10 -> V_187 = ! V_95 ;
V_95 = F_30 ( V_10 ) ;
V_10 -> V_189 = ! V_95 ;
F_32 ( V_10 ) ;
V_95 = F_37 ( V_10 , & V_250 ) ;
V_10 -> V_193 = ! V_95 ;
V_95 = F_39 ( V_10 , & V_250 ) ;
V_10 -> V_195 = ! V_95 ;
V_95 = F_43 ( V_10 , & V_250 ) ;
V_10 -> V_199 = ! V_95 ;
V_95 = F_45 ( V_10 , & V_250 ) ;
V_10 -> V_201 = ! V_95 ;
V_95 = F_64 ( V_10 , & V_250 ) ;
V_10 -> V_146 = ! V_95 ;
V_95 = F_70 ( V_10 , & V_250 ) ;
V_10 -> V_148 = ! V_95 ;
if ( V_10 -> V_197 && V_249 )
F_114 ( V_10 ) ;
V_95 = F_156 ( & V_10 -> V_26 -> V_10 . V_177 ,
& V_244 ) ;
if ( V_95 ) {
V_10 -> V_243 = 0 ;
goto error;
}
V_10 -> V_243 = ! V_95 ;
F_80 ( V_10 ) ;
V_211 = V_10 ;
return 0 ;
error:
F_144 ( V_26 ) ;
return V_95 ;
}
static void F_157 ( struct V_242 * V_26 , T_1 V_255 )
{
struct V_9 * V_10 = F_145 ( V_26 ) ;
int V_95 ;
switch ( V_255 ) {
case 0x80 :
F_124 ( V_10 ) ;
break;
case 0x81 :
case 0x82 :
case 0x83 :
F_12 ( L_111 , V_255 ) ;
break;
case 0x88 :
F_12 ( L_112 ) ;
break;
case 0x8f :
case 0x90 :
break;
case 0x8c :
case 0x8b :
F_12 ( L_113 , V_255 ) ;
break;
case 0x92 :
V_95 = F_158 ( & V_26 -> V_10 . V_177 ,
& V_244 ) ;
if ( V_95 )
F_11 ( L_114 ) ;
break;
case 0x85 :
case 0x8d :
case 0x8e :
case 0x94 :
case 0x95 :
default:
F_12 ( L_115 , V_255 ) ;
break;
}
F_159 ( V_26 -> V_256 . V_257 ,
F_160 ( & V_26 -> V_10 ) ,
V_255 , 0 ) ;
}
static int F_161 ( struct V_153 * V_153 )
{
struct V_9 * V_10 = F_145 ( F_162 ( V_153 ) ) ;
T_1 V_53 ;
if ( V_10 -> V_150 )
V_53 = F_6 ( V_10 , V_202 , V_258 ) ;
return 0 ;
}
static int F_163 ( struct V_153 * V_153 )
{
struct V_9 * V_10 = F_145 ( F_162 ( V_153 ) ) ;
int error ;
if ( V_10 -> V_150 ) {
error = F_113 ( V_10 ) ;
if ( error )
F_12 ( L_116 ) ;
}
return 0 ;
}
static int T_10 F_164 ( void )
{
int V_95 ;
if ( F_165 ( V_259 ) )
return - V_64 ;
V_144 = F_166 ( V_260 , V_261 ) ;
if ( ! V_144 ) {
F_11 ( L_117 V_260 L_118 ) ;
return - V_64 ;
}
V_95 = F_167 ( & V_262 ) ;
if ( V_95 ) {
F_11 ( L_119 , V_95 ) ;
F_83 ( V_260 , V_261 ) ;
}
return V_95 ;
}
static void T_11 F_168 ( void )
{
F_169 ( & V_262 ) ;
if ( V_144 )
F_83 ( V_260 , V_261 ) ;
}
