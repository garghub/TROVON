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
static T_1 F_10 ( struct V_9 * V_10 , T_1 V_31 , T_1 V_32 , T_1 V_37 )
{
T_1 V_11 [ V_12 ] = { V_33 , V_31 , V_32 , V_37 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
return F_7 ( V_6 ) ? V_13 [ 0 ] : V_34 ;
}
static T_1 F_11 ( struct V_9 * V_10 ,
T_1 V_31 , T_1 * V_35 , T_1 * V_38 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_31 , * V_35 , * V_38 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) )
return V_34 ;
* V_35 = V_13 [ 2 ] ;
* V_38 = V_13 [ 3 ] ;
return V_13 [ 0 ] ;
}
static int F_12 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_39 , 0 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_1 ) ;
return 0 ;
}
if ( V_13 [ 0 ] == V_40 ) {
return 1 ;
} else if ( V_13 [ 0 ] == V_41 ) {
F_14 ( L_2 ) ;
return 1 ;
} else if ( V_13 [ 0 ] == V_42 ) {
return 1 ;
} else if ( V_13 [ 0 ] == V_43 ) {
F_14 ( L_3 ) ;
}
return 0 ;
}
static void F_15 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_44 , 0 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_4 ) ;
return;
}
if ( V_13 [ 0 ] == V_40 )
return;
else if ( V_13 [ 0 ] == V_45 )
F_14 ( L_5 ) ;
else if ( V_13 [ 0 ] == V_43 )
F_14 ( L_3 ) ;
}
static T_1 F_16 ( struct V_9 * V_10 , T_1 V_31 , T_1 * V_35 )
{
T_1 V_11 [ V_12 ] = { V_46 , V_31 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) )
return V_34 ;
* V_35 = V_13 [ 2 ] ;
return V_13 [ 0 ] ;
}
static T_1 F_17 ( struct V_9 * V_10 , T_1 V_31 , T_1 V_32 )
{
T_1 V_11 [ V_12 ] = { V_47 , V_31 , V_32 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
return F_7 ( V_6 ) ? V_13 [ 0 ] : V_34 ;
}
static int F_18 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_46 , V_48 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_12 ( V_10 ) )
return 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_15 ( V_10 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_6 ) ;
return 0 ;
} else if ( V_13 [ 0 ] == V_42 ) {
F_14 ( L_7 ) ;
return 0 ;
}
return 1 ;
}
static void F_19 ( struct V_49 * V_50 ,
enum V_51 V_52 )
{
struct V_9 * V_10 = F_20 ( V_50 ,
struct V_9 , V_53 ) ;
T_1 V_54 , V_55 ;
if ( ! F_12 ( V_10 ) )
return;
V_54 = V_52 ? 1 : 0 ;
V_55 = F_17 ( V_10 , V_48 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_8 ) ;
return;
} else if ( V_55 == V_42 ) {
F_14 ( L_9 ) ;
return;
}
}
static enum V_51 F_21 ( struct V_49 * V_50 )
{
struct V_9 * V_10 = F_20 ( V_50 ,
struct V_9 , V_53 ) ;
T_1 V_54 , V_55 ;
if ( ! F_12 ( V_10 ) )
return V_56 ;
V_55 = F_16 ( V_10 , V_48 , & V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_8 ) ;
return V_56 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_9 ) ;
return V_56 ;
}
return V_54 ? V_58 : V_56 ;
}
static int F_22 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_46 , V_59 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_12 ( V_10 ) )
return 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_15 ( V_10 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_13 ( L_10 ) ;
return 0 ;
} else if ( V_13 [ 0 ] == V_42 ) {
F_14 ( L_11 ) ;
return 0 ;
}
if ( V_13 [ 3 ] == V_60 )
V_10 -> V_61 = 2 ;
else
V_10 -> V_61 = 1 ;
V_10 -> V_62 = V_13 [ 2 ] & V_63 ;
V_10 -> V_64 = V_13 [ 2 ] >> V_65 ;
return 1 ;
}
static int F_23 ( struct V_9 * V_10 , T_1 time )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_59 , time ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_12 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_13 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_24 ( struct V_9 * V_10 , T_1 * time )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_59 , time ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_14 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_13 ) ;
return - V_66 ;
}
return 0 ;
}
static enum V_51 F_25 ( struct V_49 * V_50 )
{
struct V_9 * V_10 = F_20 ( V_50 ,
struct V_9 , V_67 ) ;
T_1 V_54 , V_55 ;
V_55 = F_8 ( V_10 , V_68 , & V_54 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_15 ) ;
return V_56 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_16 ) ;
return V_56 ;
}
return V_54 ? V_58 : V_56 ;
}
static void F_26 ( struct V_49 * V_50 ,
enum V_51 V_52 )
{
struct V_9 * V_10 = F_20 ( V_50 ,
struct V_9 , V_67 ) ;
T_1 V_54 , V_55 ;
V_54 = V_52 ? 1 : 0 ;
V_55 = F_6 ( V_10 , V_68 , V_54 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_17 ) ;
return;
} else if ( V_55 == V_42 ) {
F_14 ( L_16 ) ;
return;
}
}
static int F_27 ( struct V_9 * V_10 , T_1 V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_69 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_18 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
return - V_66 ;
}
return 0 ;
}
static int F_28 ( struct V_9 * V_10 , T_1 * V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_69 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_19 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
return - V_66 ;
}
return 0 ;
}
static int F_29 ( struct V_9 * V_10 )
{
T_2 V_6 ;
T_1 V_11 [ V_12 ] = { V_36 , V_70 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_20 ) ;
} else if ( V_13 [ 0 ] == V_71 ) {
F_14 ( L_21 ) ;
} else if ( V_13 [ 0 ] == V_57 ) {
V_11 [ 3 ] = 1 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 )
F_13 ( L_20 ) ;
else if ( V_13 [ 0 ] == V_72 )
return 1 ;
}
return 0 ;
}
static enum V_51
F_30 ( struct V_49 * V_50 )
{
struct V_9 * V_10 = F_20 ( V_50 ,
struct V_9 , V_73 ) ;
T_1 V_11 [ V_12 ] = { V_36 , V_70 , 0 , 1 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_13 ( L_20 ) ;
return V_56 ;
}
return V_13 [ 2 ] ? V_58 : V_56 ;
}
static void F_31 ( struct V_49 * V_50 ,
enum V_51 V_52 )
{
struct V_9 * V_10 = F_20 ( V_50 ,
struct V_9 , V_73 ) ;
T_1 V_11 [ V_12 ] = { V_33 , V_70 , 0 , 1 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_11 [ 2 ] = ( V_52 ) ? 1 : 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_13 ( L_22 ) ;
return;
}
}
static int F_32 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_74 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_13 ( L_23 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_75 ||
V_13 [ 0 ] == V_76 ) {
F_13 ( L_24 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_42 ) {
F_14 ( L_25 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_33 ( struct V_9 * V_10 ,
T_1 * V_77 , T_1 * V_78 )
{
T_1 V_11 [ V_12 ] = { V_36 , V_79 , 0 , 1 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_13 ( L_23 ) ;
return - V_8 ;
}
* V_77 = V_13 [ 2 ] ;
* V_78 = V_13 [ 4 ] ;
return 0 ;
}
static int F_34 ( struct V_9 * V_10 ,
T_1 * V_80 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_81 , V_80 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_26 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_27 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_35 ( struct V_9 * V_10 ,
T_1 V_80 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_81 , V_80 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_26 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_27 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_36 ( struct V_9 * V_10 ,
T_1 * V_80 )
{
T_1 V_11 [ V_12 ] = { V_46 , V_81 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_11 [ 5 ] = V_82 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_15 ( V_10 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_28 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_42 ) {
F_14 ( L_27 ) ;
return - V_66 ;
} else if ( V_13 [ 0 ] == V_57 ) {
return - V_8 ;
}
* V_80 = V_13 [ 2 ] ;
return 0 ;
}
static int F_37 ( struct V_9 * V_10 ,
T_1 V_80 )
{
T_1 V_11 [ V_12 ] = { V_47 , V_81 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_11 [ 2 ] = V_80 ;
V_11 [ 5 ] = V_82 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_15 ( V_10 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_29 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_42 ) {
F_14 ( L_27 ) ;
return - V_66 ;
} else if ( V_13 [ 0 ] == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_38 ( struct V_9 * V_10 ,
T_1 * V_54 )
{
T_1 V_11 [ V_12 ] = { V_46 , V_81 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_11 [ 5 ] = V_83 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_15 ( V_10 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_28 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_42 ||
V_13 [ 0 ] == V_57 ) {
F_14 ( L_27 ) ;
return - V_66 ;
}
* V_54 = V_13 [ 2 ] ;
return 0 ;
}
static int F_39 ( struct V_9 * V_10 ,
T_1 V_54 )
{
T_1 V_11 [ V_12 ] = { V_47 , V_81 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_11 [ 2 ] = V_54 ;
V_11 [ 5 ] = V_83 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_15 ( V_10 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_29 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_42 ) {
F_14 ( L_27 ) ;
return - V_66 ;
} else if ( V_13 [ 0 ] == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_40 ( struct V_9 * V_10 , T_1 * V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_84 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_26 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_27 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_41 ( struct V_9 * V_10 , T_1 V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_84 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_26 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_27 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_42 ( struct V_9 * V_10 , T_1 * V_80 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_85 , V_80 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_30 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_31 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_43 ( struct V_9 * V_10 , T_1 V_80 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_85 , V_80 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_32 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_31 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_44 ( struct V_9 * V_10 , T_1 * V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_86 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_33 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_34 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_45 ( struct V_9 * V_10 , T_1 V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_86 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_35 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_36 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_46 ( struct V_9 * V_10 , T_1 * V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_87 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_37 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_38 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_47 ( struct V_9 * V_10 , T_1 V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_87 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_39 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_38 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static T_1 F_48 ( struct V_9 * V_10 , bool * V_88 )
{
T_1 V_89 ;
T_1 V_3 , V_90 ;
V_3 = 0 ;
V_90 = 0 ;
V_89 = F_11 ( V_10 , V_91 , & V_3 , & V_90 ) ;
if ( V_89 == V_72 )
* V_88 = ( V_3 & V_92 ) ? true : false ;
return V_89 ;
}
static T_1 F_49 ( struct V_9 * V_10 , bool * V_93 )
{
T_1 V_89 ;
T_1 V_3 , V_90 ;
V_3 = 0 ;
V_90 = 0x0001 ;
V_89 = F_11 ( V_10 , V_91 , & V_3 , & V_90 ) ;
* V_93 = V_3 & V_94 ;
return V_89 ;
}
static int F_50 ( void * V_95 , bool V_96 )
{
struct V_9 * V_10 = V_95 ;
T_1 V_97 , V_98 ;
T_1 V_3 ;
int V_99 ;
bool V_93 ;
V_3 = ( V_96 == false ) ;
F_51 ( & V_10 -> V_100 ) ;
if ( F_49 ( V_10 , & V_93 ) != V_72 ) {
V_99 = - V_8 ;
goto V_13;
}
if ( ! V_93 ) {
V_99 = 0 ;
goto V_13;
}
V_97 = F_10 ( V_10 , V_91 , V_3 , V_101 ) ;
V_98 = F_10 ( V_10 , V_91 , V_3 , V_102 ) ;
if ( V_97 != V_72 || V_98 != V_72 )
V_99 = - V_8 ;
else
V_99 = 0 ;
V_13:
F_52 ( & V_10 -> V_100 ) ;
return V_99 ;
}
static void F_53 ( struct V_103 * V_103 , void * V_95 )
{
bool V_104 ;
bool V_3 ;
T_1 V_89 ;
struct V_9 * V_10 = V_95 ;
F_51 ( & V_10 -> V_100 ) ;
V_89 = F_49 ( V_10 , & V_3 ) ;
if ( V_89 != V_72 ) {
F_52 ( & V_10 -> V_100 ) ;
return;
}
V_104 = V_3 ;
F_52 ( & V_10 -> V_100 ) ;
if ( F_54 ( V_103 , ! V_104 ) )
F_50 ( V_95 , true ) ;
}
static int F_55 ( struct V_9 * V_10 , bool * V_105 )
{
T_1 V_89 ;
T_1 V_6 ;
V_89 = F_8 ( V_10 , V_106 , & V_6 ) ;
* V_105 = ! V_6 ;
return V_89 == V_72 ? 0 : - V_8 ;
}
static int F_56 ( struct V_9 * V_10 , bool V_107 )
{
T_1 V_89 ;
T_1 V_3 = ! V_107 ;
V_89 = F_6 ( V_10 , V_106 , V_3 ) ;
return V_89 == V_72 ? 0 : - V_8 ;
}
static int F_57 ( struct V_9 * V_10 )
{
T_1 V_89 ;
T_1 V_3 ;
int V_52 = 0 ;
if ( V_10 -> V_108 ) {
bool V_105 ;
int V_109 = F_55 ( V_10 , & V_105 ) ;
if ( V_109 )
return V_109 ;
if ( V_105 )
return 0 ;
V_52 ++ ;
}
V_89 = F_8 ( V_10 , V_110 , & V_3 ) ;
if ( V_89 == V_72 )
return V_52 + ( V_3 >> V_111 ) ;
return - V_8 ;
}
static int F_58 ( struct V_112 * V_113 )
{
struct V_9 * V_10 = F_59 ( V_113 ) ;
return F_57 ( V_10 ) ;
}
static int F_60 ( struct V_114 * V_115 , void * V_116 )
{
struct V_9 * V_10 = V_115 -> V_117 ;
int V_3 ;
int V_118 ;
if ( ! V_10 -> V_119 )
return - V_66 ;
V_118 = V_10 -> V_119 -> V_120 . V_121 + 1 ;
V_3 = F_58 ( V_10 -> V_119 ) ;
if ( V_3 >= 0 ) {
F_61 ( V_115 , L_40 , V_3 ) ;
F_61 ( V_115 , L_41 , V_118 ) ;
return 0 ;
}
F_13 ( L_42 ) ;
return - V_8 ;
}
static int F_62 ( struct V_122 * V_122 , struct V_123 * V_123 )
{
return F_63 ( V_123 , F_60 , F_64 ( V_122 ) ) ;
}
static int F_65 ( struct V_9 * V_10 , int V_3 )
{
T_1 V_89 ;
if ( V_10 -> V_108 ) {
bool V_107 = ! V_3 ;
int V_109 = F_56 ( V_10 , V_107 ) ;
if ( V_109 )
return V_109 ;
if ( V_3 )
V_3 -- ;
}
V_3 = V_3 << V_111 ;
V_89 = F_6 ( V_10 , V_110 , V_3 ) ;
return V_89 == V_72 ? 0 : - V_8 ;
}
static int F_66 ( struct V_112 * V_113 )
{
struct V_9 * V_10 = F_59 ( V_113 ) ;
return F_65 ( V_10 , V_113 -> V_120 . V_52 ) ;
}
static T_3 F_67 ( struct V_123 * V_123 , const char T_4 * V_124 ,
T_5 V_22 , T_6 * V_125 )
{
struct V_9 * V_10 = F_64 ( F_68 ( V_123 ) ) ;
char V_126 [ 42 ] ;
T_5 V_127 ;
int V_3 ;
int V_109 ;
int V_118 = V_10 -> V_119 -> V_120 . V_121 + 1 ;
V_127 = F_69 ( V_22 , sizeof( V_126 ) - 1 ) ;
if ( F_70 ( V_126 , V_124 , V_127 ) )
return - V_128 ;
V_126 [ V_127 ] = '\0' ;
if ( sscanf ( V_126 , L_43 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 < V_118 ) {
V_109 = F_65 ( V_10 , V_3 ) ;
if ( V_109 == 0 )
V_109 = V_22 ;
} else {
V_109 = - V_129 ;
}
return V_109 ;
}
static int F_71 ( struct V_9 * V_10 , T_1 * V_6 )
{
T_1 V_89 ;
V_89 = F_8 ( V_10 , V_130 , V_6 ) ;
return V_89 == V_72 ? 0 : - V_8 ;
}
static int F_72 ( struct V_114 * V_115 , void * V_116 )
{
struct V_9 * V_10 = V_115 -> V_117 ;
T_1 V_3 ;
int V_109 ;
V_109 = F_71 ( V_10 , & V_3 ) ;
if ( ! V_109 ) {
int V_131 = ( V_3 & V_132 ) ? 1 : 0 ;
int V_133 = ( V_3 & V_134 ) ? 1 : 0 ;
int V_135 = ( V_3 & V_136 ) ? 1 : 0 ;
F_61 ( V_115 , L_44 , V_131 ) ;
F_61 ( V_115 , L_45 , V_133 ) ;
F_61 ( V_115 , L_46 , V_135 ) ;
}
return V_109 ;
}
static int F_73 ( struct V_122 * V_122 , struct V_123 * V_123 )
{
return F_63 ( V_123 , F_72 , F_64 ( V_122 ) ) ;
}
static T_3 F_74 ( struct V_123 * V_123 , const char T_4 * V_124 ,
T_5 V_22 , T_6 * V_125 )
{
struct V_9 * V_10 = F_64 ( F_68 ( V_123 ) ) ;
char * V_126 , * V_137 ;
int V_109 ;
int V_3 ;
int V_138 = V_22 ;
int V_139 = - 1 ;
int V_140 = - 1 ;
int V_141 = - 1 ;
T_1 V_142 ;
V_126 = F_75 ( V_22 + 1 , V_143 ) ;
if ( ! V_126 )
return - V_144 ;
if ( F_70 ( V_126 , V_124 , V_22 ) ) {
F_76 ( V_126 ) ;
return - V_128 ;
}
V_126 [ V_22 ] = '\0' ;
V_137 = V_126 ;
while ( V_138 ) {
if ( sscanf ( V_137 , L_47 , & V_3 ) == 1 )
V_139 = V_3 & 1 ;
else if ( sscanf ( V_137 , L_48 , & V_3 ) == 1 )
V_140 = V_3 & 1 ;
else if ( sscanf ( V_137 , L_49 , & V_3 ) == 1 )
V_141 = V_3 & 1 ;
do {
++ V_137 ;
-- V_138 ;
} while ( V_138 && * ( V_137 - 1 ) != ';' );
}
F_76 ( V_126 ) ;
V_109 = F_71 ( V_10 , & V_142 ) ;
if ( ! V_109 ) {
unsigned int V_145 = V_142 ;
if ( V_139 != - 1 )
F_1 ( & V_145 , V_132 , V_139 ) ;
if ( V_140 != - 1 )
F_1 ( & V_145 , V_134 , V_140 ) ;
if ( V_141 != - 1 )
F_1 ( & V_145 , V_136 , V_141 ) ;
if ( V_145 != V_142 )
V_109 = F_2 ( V_146 , V_145 ) ;
}
return V_109 ? V_109 : V_22 ;
}
static int F_77 ( struct V_9 * V_10 , T_1 * V_6 )
{
T_1 V_89 ;
V_89 = F_8 ( V_10 , V_147 , V_6 ) ;
return V_89 == V_72 ? 0 : - V_8 ;
}
static int F_78 ( struct V_114 * V_115 , void * V_116 )
{
struct V_9 * V_10 = V_115 -> V_117 ;
int V_109 ;
T_1 V_3 ;
V_109 = F_77 ( V_10 , & V_3 ) ;
if ( ! V_109 ) {
F_61 ( V_115 , L_50 , ( V_3 > 0 ) ) ;
F_61 ( V_115 , L_51 , V_10 -> V_148 ) ;
}
return V_109 ;
}
static int F_79 ( struct V_122 * V_122 , struct V_123 * V_123 )
{
return F_63 ( V_123 , F_78 , F_64 ( V_122 ) ) ;
}
static T_3 F_80 ( struct V_123 * V_123 , const char T_4 * V_124 ,
T_5 V_22 , T_6 * V_125 )
{
struct V_9 * V_10 = F_64 ( F_68 ( V_123 ) ) ;
char V_126 [ 42 ] ;
T_5 V_127 ;
int V_3 ;
T_1 V_89 ;
V_127 = F_69 ( V_22 , sizeof( V_126 ) - 1 ) ;
if ( F_70 ( V_126 , V_124 , V_127 ) )
return - V_128 ;
V_126 [ V_127 ] = '\0' ;
if ( sscanf ( V_126 , L_52 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 <= 1 ) {
V_89 = F_6 ( V_10 , V_147 , V_3 ) ;
if ( V_89 == V_72 )
V_10 -> V_148 = V_3 ;
else
return - V_8 ;
} else {
return - V_129 ;
}
return V_22 ;
}
static int F_81 ( struct V_114 * V_115 , void * V_116 )
{
struct V_9 * V_10 = V_115 -> V_117 ;
T_1 V_89 ;
T_1 V_3 ;
if ( ! V_10 -> V_149 && V_10 -> V_150 ) {
V_89 = F_8 ( V_10 , V_151 , & V_3 ) ;
if ( V_89 == V_72 ) {
V_10 -> V_149 = 1 ;
V_10 -> V_152 = V_3 ;
} else if ( V_89 == V_153 ) {
} else if ( V_89 == V_42 ) {
V_89 = F_6 ( V_10 , V_151 , 1 ) ;
F_82 ( L_53 ) ;
} else {
F_13 ( L_54 ) ;
return - V_8 ;
}
}
F_61 ( V_115 , L_55 , V_10 -> V_149 ) ;
F_61 ( V_115 , L_56 , V_10 -> V_152 ) ;
return 0 ;
}
static int F_83 ( struct V_122 * V_122 , struct V_123 * V_123 )
{
return F_63 ( V_123 , F_81 , F_64 ( V_122 ) ) ;
}
static T_3 F_84 ( struct V_123 * V_123 , const char T_4 * V_124 ,
T_5 V_22 , T_6 * V_125 )
{
struct V_9 * V_10 = F_64 ( F_68 ( V_123 ) ) ;
char V_126 [ 42 ] ;
T_5 V_127 ;
int V_3 ;
V_127 = F_69 ( V_22 , sizeof( V_126 ) - 1 ) ;
if ( F_70 ( V_126 , V_124 , V_127 ) )
return - V_128 ;
V_126 [ V_127 ] = '\0' ;
if ( sscanf ( V_126 , L_57 , & V_3 ) == 1 && V_3 == 0 )
V_10 -> V_149 = 0 ;
else
return - V_129 ;
return V_22 ;
}
static int F_85 ( struct V_114 * V_115 , void * V_116 )
{
F_61 ( V_115 , L_58 , V_154 ) ;
F_61 ( V_115 , L_59 , V_155 ) ;
return 0 ;
}
static int F_86 ( struct V_122 * V_122 , struct V_123 * V_123 )
{
return F_63 ( V_123 , F_85 , F_64 ( V_122 ) ) ;
}
static void F_87 ( struct V_9 * V_10 )
{
if ( V_10 -> V_119 )
F_88 ( L_60 , V_156 | V_157 , V_158 ,
& V_159 , V_10 ) ;
if ( V_10 -> V_160 )
F_88 ( L_61 , V_156 | V_157 , V_158 ,
& V_161 , V_10 ) ;
if ( V_10 -> V_162 )
F_88 ( L_62 , V_156 | V_157 , V_158 ,
& V_163 , V_10 ) ;
if ( V_10 -> V_164 )
F_88 ( L_63 , V_156 | V_157 , V_158 ,
& V_165 , V_10 ) ;
F_88 ( L_64 , V_156 , V_158 ,
& V_166 , V_10 ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
if ( V_10 -> V_119 )
F_90 ( L_60 , V_158 ) ;
if ( V_10 -> V_160 )
F_90 ( L_61 , V_158 ) ;
if ( V_10 -> V_162 )
F_90 ( L_62 , V_158 ) ;
if ( V_10 -> V_164 )
F_90 ( L_63 , V_158 ) ;
F_90 ( L_64 , V_158 ) ;
}
static T_3 F_91 ( struct V_167 * V_10 ,
struct V_168 * V_169 , char * V_124 )
{
return sprintf ( V_124 , L_65 , V_154 ) ;
}
static T_3 F_92 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
const char * V_124 , T_5 V_22 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 V_55 ;
int V_54 ;
int V_109 ;
V_109 = F_94 ( V_124 , 0 , & V_54 ) ;
if ( V_109 )
return V_109 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_129 ;
V_55 = F_6 ( V_170 , V_147 , V_54 ) ;
if ( V_55 == V_34 )
return - V_8 ;
else if ( V_55 == V_42 )
return - V_66 ;
return V_22 ;
}
static T_3 F_95 ( struct V_167 * V_10 ,
struct V_168 * V_169 , char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 V_3 ;
int V_109 ;
V_109 = F_77 ( V_170 , & V_3 ) ;
if ( V_109 )
return V_109 ;
return sprintf ( V_124 , L_66 , V_3 ) ;
}
static T_3 F_96 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
const char * V_124 , T_5 V_22 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
int V_80 ;
int time ;
int V_109 ;
V_109 = F_94 ( V_124 , 0 , & V_80 ) ;
if ( V_109 )
return V_109 ;
if ( V_170 -> V_61 == 1 ) {
if ( V_80 != V_171 && V_80 != V_172 )
return - V_129 ;
} else if ( V_170 -> V_61 == 2 ) {
if ( V_80 != V_172 && V_80 != V_173 &&
V_80 != V_174 )
return - V_129 ;
}
if ( V_170 -> V_62 != V_80 ) {
time = V_170 -> V_64 << V_65 ;
if ( V_170 -> V_61 == 1 ) {
time |= V_170 -> V_62 ;
} else if ( V_170 -> V_61 == 2 ) {
time |= V_80 ;
}
V_109 = F_23 ( V_170 , time ) ;
if ( V_109 )
return V_109 ;
V_170 -> V_62 = V_80 ;
}
return V_22 ;
}
static T_3 F_97 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 time ;
if ( F_24 ( V_170 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_124 , L_67 , time & V_63 ) ;
}
static T_3 F_98 ( struct V_167 * V_10 ,
struct V_168 * V_169 , char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
return sprintf ( V_124 , L_66 , V_170 -> V_61 ) ;
}
static T_3 F_99 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
if ( V_170 -> V_61 == 1 )
return sprintf ( V_124 , L_68 ,
V_171 , V_172 ) ;
return sprintf ( V_124 , L_69 ,
V_172 , V_173 , V_174 ) ;
}
static T_3 F_100 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
const char * V_124 , T_5 V_22 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
int time ;
int V_109 ;
V_109 = F_94 ( V_124 , 0 , & time ) ;
if ( V_109 )
return V_109 ;
if ( V_170 -> V_61 == 1 ) {
if ( time < 0 || time > 60 )
return - V_129 ;
} else if ( V_170 -> V_61 == 2 ) {
if ( time < 1 || time > 60 )
return - V_129 ;
}
if ( V_170 -> V_64 != time ) {
time = time << V_65 ;
if ( V_170 -> V_61 == 1 )
time |= V_171 ;
else if ( V_170 -> V_61 == 2 )
time |= V_172 ;
V_109 = F_23 ( V_170 , time ) ;
if ( V_109 )
return V_109 ;
V_170 -> V_64 = time >> V_65 ;
}
return V_22 ;
}
static T_3 F_101 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 time ;
if ( F_24 ( V_170 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_124 , L_67 , time >> V_65 ) ;
}
static T_3 F_102 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
const char * V_124 , T_5 V_22 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
int V_54 ;
int V_109 ;
V_109 = F_94 ( V_124 , 0 , & V_54 ) ;
if ( V_109 )
return V_109 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_129 ;
V_109 = F_27 ( V_170 , V_54 ) ;
if ( V_109 )
return V_109 ;
return V_22 ;
}
static T_3 F_103 ( struct V_167 * V_10 ,
struct V_168 * V_169 , char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 V_54 ;
int V_109 ;
V_109 = F_28 ( V_170 , & V_54 ) ;
if ( V_109 < 0 )
return V_109 ;
return sprintf ( V_124 , L_67 , V_54 ) ;
}
static T_3 F_104 ( struct V_167 * V_10 ,
struct V_168 * V_169 , char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 V_175 , V_176 , V_177 ;
T_7 V_178 , V_179 , V_78 ;
int V_109 ;
V_175 = V_176 = 0 ;
V_109 = F_33 ( V_170 , & V_175 , & V_176 ) ;
if ( V_109 < 0 )
return V_109 ;
V_178 = V_175 & V_180 ;
V_177 = V_175 >> V_65 ;
V_179 = V_177 & V_180 ;
V_78 = V_176 & V_180 ;
return sprintf ( V_124 , L_70 , V_178 , V_179 , V_78 ) ;
}
static T_3 F_105 ( struct V_167 * V_10 ,
struct V_168 * V_169 , char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 V_80 ;
int V_109 ;
V_109 = F_34 ( V_170 , & V_80 ) ;
if ( V_109 < 0 )
return V_109 ;
return sprintf ( V_124 , L_71 , V_80 & V_181 ) ;
}
static T_3 F_106 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
const char * V_124 , T_5 V_22 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 V_80 ;
int V_54 ;
int V_109 ;
V_109 = F_94 ( V_124 , 0 , & V_54 ) ;
if ( V_109 )
return V_109 ;
if ( V_54 != 0 && V_54 != 1 && V_54 != 2 )
return - V_129 ;
if ( V_54 == 0 )
V_80 = V_182 ;
else if ( V_54 == 1 )
V_80 = V_183 ;
else if ( V_54 == 2 )
V_80 = V_184 ;
V_109 = F_35 ( V_170 , V_80 ) ;
if ( V_109 )
return V_109 ;
return V_22 ;
}
static T_3 F_107 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 V_54 ;
int V_185 ;
int V_6 ;
int V_109 ;
int V_177 ;
V_109 = F_36 ( V_170 , & V_54 ) ;
if ( V_109 < 0 )
return V_109 ;
V_177 = V_54 & V_186 ;
V_6 = ( V_177 == 0x4 ) ? 1 : 0 ;
V_185 = V_54 >> V_65 ;
return sprintf ( V_124 , L_72 , V_6 , V_185 ) ;
}
static T_3 F_108 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
const char * V_124 , T_5 V_22 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 V_6 ;
int V_3 ;
int V_109 ;
int V_177 ;
V_109 = F_94 ( V_124 , 0 , & V_3 ) ;
if ( V_109 )
return V_109 ;
if ( V_3 < 0 || V_3 > 100 )
return - V_129 ;
if ( V_3 == 0 ) {
V_177 = V_170 -> V_187 << V_65 ;
V_6 = V_177 | V_188 ;
} else {
V_177 = V_3 << V_65 ;
V_6 = V_177 | V_189 ;
}
V_109 = F_37 ( V_170 , V_6 ) ;
if ( V_109 < 0 )
return V_109 ;
V_170 -> V_187 = V_6 >> V_65 ;
return V_22 ;
}
static T_3 F_109 ( struct V_167 * V_10 ,
struct V_168 * V_169 , char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 V_54 ;
int V_109 ;
V_109 = F_38 ( V_170 , & V_54 ) ;
if ( V_109 < 0 )
return V_109 ;
return sprintf ( V_124 , L_66 , V_54 ) ;
}
static T_3 F_110 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
const char * V_124 , T_5 V_22 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
int V_54 ;
int V_109 ;
V_109 = F_94 ( V_124 , 0 , & V_54 ) ;
if ( V_109 )
return V_109 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_129 ;
V_109 = F_39 ( V_170 , V_54 ) ;
if ( V_109 )
return V_109 ;
return V_22 ;
}
static T_3 F_111 ( struct V_167 * V_10 ,
struct V_168 * V_169 , char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 V_54 ;
int V_109 ;
V_109 = F_40 ( V_170 , & V_54 ) ;
if ( V_109 < 0 )
return V_109 ;
return sprintf ( V_124 , L_66 , V_54 ) ;
}
static T_3 F_112 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
const char * V_124 , T_5 V_22 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
int V_54 ;
int V_109 ;
V_109 = F_94 ( V_124 , 0 , & V_54 ) ;
if ( V_109 )
return V_109 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_129 ;
V_109 = F_41 ( V_170 , V_54 ) ;
if ( V_109 )
return V_109 ;
return V_22 ;
}
static T_3 F_113 ( struct V_167 * V_10 ,
struct V_168 * V_169 , char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
int V_80 ;
int V_109 ;
V_109 = F_42 ( V_170 , & V_80 ) ;
if ( V_109 < 0 )
return V_109 ;
return sprintf ( V_124 , L_66 , V_80 ) ;
}
static T_3 F_114 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
const char * V_124 , T_5 V_22 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
int V_80 ;
int V_109 ;
V_109 = F_94 ( V_124 , 0 , & V_80 ) ;
if ( V_109 )
return V_109 ;
if ( V_80 != 0 && V_80 != 1 )
return - V_129 ;
V_109 = F_43 ( V_170 , V_80 ) ;
if ( V_109 )
return V_109 ;
F_14 ( L_73 ) ;
return V_22 ;
}
static T_3 F_115 ( struct V_167 * V_10 ,
struct V_168 * V_169 , char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 V_54 ;
int V_109 ;
V_109 = F_44 ( V_170 , & V_54 ) ;
if ( V_109 < 0 )
return V_109 ;
return sprintf ( V_124 , L_66 , V_54 ) ;
}
static T_3 F_116 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
const char * V_124 , T_5 V_22 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
int V_54 ;
int V_109 ;
V_109 = F_94 ( V_124 , 0 , & V_54 ) ;
if ( V_109 )
return V_109 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_129 ;
V_109 = F_45 ( V_170 , V_54 ) ;
if ( V_109 )
return V_109 ;
F_14 ( L_74 ) ;
return V_22 ;
}
static T_3 F_117 ( struct V_167 * V_10 ,
struct V_168 * V_169 , char * V_124 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
T_1 V_54 ;
int V_109 ;
V_109 = F_46 ( V_170 , & V_54 ) ;
if ( V_109 < 0 )
return V_109 ;
return sprintf ( V_124 , L_66 , V_54 ) ;
}
static T_3 F_118 ( struct V_167 * V_10 ,
struct V_168 * V_169 ,
const char * V_124 , T_5 V_22 )
{
struct V_9 * V_170 = F_93 ( V_10 ) ;
int V_54 ;
int V_109 ;
V_109 = F_94 ( V_124 , 0 , & V_54 ) ;
if ( V_109 )
return V_109 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_129 ;
V_109 = F_47 ( V_170 , V_54 ) ;
if ( V_109 )
return V_109 ;
F_14 ( L_75 ) ;
return V_22 ;
}
static T_8 F_119 ( struct V_190 * V_191 ,
struct V_192 * V_169 , int V_193 )
{
struct V_167 * V_10 = F_20 ( V_191 , struct V_167 , V_191 ) ;
struct V_9 * V_194 = F_93 ( V_10 ) ;
bool V_195 = true ;
if ( V_169 == & V_196 . V_169 )
V_195 = ( V_194 -> V_162 ) ? true : false ;
else if ( V_169 == & V_197 . V_169 )
V_195 = ( V_194 -> V_198 ) ? true : false ;
else if ( V_169 == & V_199 . V_169 )
V_195 = ( V_194 -> V_62 == V_172 ) ? true : false ;
else if ( V_169 == & V_200 . V_169 )
V_195 = ( V_194 -> V_201 ) ? true : false ;
else if ( V_169 == & V_202 . V_169 )
V_195 = ( V_194 -> V_203 ) ? true : false ;
else if ( V_169 == & V_204 . V_169 )
V_195 = ( V_194 -> V_205 ) ? true : false ;
else if ( V_169 == & V_206 . V_169 )
V_195 = ( V_194 -> V_205 ) ? true : false ;
else if ( V_169 == & V_207 . V_169 )
V_195 = ( V_194 -> V_208 ) ? true : false ;
else if ( V_169 == & V_209 . V_169 )
V_195 = ( V_194 -> V_210 ) ? true : false ;
else if ( V_169 == & V_211 . V_169 )
V_195 = ( V_194 -> V_212 ) ? true : false ;
else if ( V_169 == & V_213 . V_169 )
V_195 = ( V_194 -> V_214 ) ? true : false ;
else if ( V_169 == & V_215 . V_169 )
V_195 = ( V_194 -> V_216 ) ? true : false ;
return V_195 ? V_169 -> V_80 : 0 ;
}
static int F_120 ( struct V_9 * V_10 )
{
T_2 V_6 ;
T_1 V_55 ;
V_6 = F_5 ( V_10 -> V_26 -> V_27 ,
L_76 , NULL , NULL ) ;
if ( F_9 ( V_6 ) )
return - V_66 ;
V_55 = F_6 ( V_10 , V_217 , V_218 ) ;
if ( V_55 == V_34 )
return - V_8 ;
else if ( V_55 == V_42 )
return - V_66 ;
return 0 ;
}
static bool F_121 ( unsigned char V_95 , unsigned char V_219 ,
struct V_220 * V_221 )
{
if ( V_219 & V_222 )
return false ;
if ( F_122 ( V_95 == 0xe0 ) )
return false ;
if ( ( V_95 & 0x7f ) == V_223 ) {
F_123 ( & V_224 -> V_225 ) ;
return true ;
}
return false ;
}
static void F_124 ( struct V_226 * V_227 )
{
T_9 V_228 = F_125 () ;
T_2 V_6 ;
if ( ! V_228 )
return;
V_6 = F_5 ( V_228 , L_77 , NULL , NULL ) ;
if ( F_9 ( V_6 ) )
F_13 ( L_78 ) ;
}
static int F_126 ( struct V_9 * V_10 )
{
unsigned long long V_3 ;
T_2 V_6 ;
V_6 = F_127 ( V_10 -> V_26 -> V_27 , L_79 ,
NULL , & V_3 ) ;
if ( F_9 ( V_6 ) ) {
F_13 ( L_80 ) ;
return - V_8 ;
}
return V_3 ;
}
static void F_128 ( struct V_9 * V_10 ,
int V_229 )
{
if ( V_229 == 0x100 )
return;
if ( V_229 & 0x80 )
return;
if ( ! F_129 ( V_10 -> V_164 , V_229 , 1 , true ) )
F_14 ( L_81 , V_229 ) ;
}
static void F_130 ( struct V_9 * V_10 )
{
T_1 V_89 , V_3 ;
int V_230 = 3 ;
int V_229 ;
if ( V_10 -> V_231 ) {
V_229 = F_126 ( V_10 ) ;
if ( V_229 < 0 )
F_13 ( L_82 ) ;
else if ( V_229 != 0 )
F_128 ( V_10 , V_229 ) ;
} else if ( V_10 -> V_150 ) {
do {
V_89 = F_8 ( V_10 , V_151 , & V_3 ) ;
switch ( V_89 ) {
case V_72 :
F_128 ( V_10 , ( int ) V_3 ) ;
break;
case V_42 :
V_89 =
F_6 ( V_10 , V_151 , 1 ) ;
F_82 ( L_53 ) ;
default:
V_230 -- ;
break;
}
} while ( V_230 && V_89 != V_153 );
}
}
static int F_131 ( struct V_9 * V_10 )
{
T_9 V_228 ;
int error ;
T_1 V_89 ;
const struct V_232 * V_233 = V_234 ;
V_10 -> V_164 = F_132 () ;
if ( ! V_10 -> V_164 )
return - V_144 ;
V_10 -> V_164 -> V_235 = L_83 ;
V_10 -> V_164 -> V_236 = L_84 ;
V_10 -> V_164 -> V_237 . V_238 = V_239 ;
if ( F_133 ( V_240 ) )
V_233 = V_241 ;
error = F_134 ( V_10 -> V_164 , V_233 , NULL ) ;
if ( error )
goto V_242;
V_228 = F_125 () ;
if ( V_228 && F_135 ( V_228 , L_77 ) ) {
F_136 ( & V_10 -> V_225 , F_124 ) ;
error = F_137 ( F_121 ) ;
if ( error ) {
F_13 ( L_85 ) ;
goto V_243;
}
V_10 -> V_244 = 1 ;
}
if ( F_135 ( V_10 -> V_26 -> V_27 , L_79 ) )
V_10 -> V_231 = 1 ;
else {
V_89 = F_6 ( V_10 , V_151 , 1 ) ;
if ( V_89 == V_72 )
V_10 -> V_150 = 1 ;
}
if ( ! V_10 -> V_231 && ! V_10 -> V_150 ) {
F_138 ( L_86 ) ;
goto V_245;
}
error = F_120 ( V_10 ) ;
if ( error ) {
F_14 ( L_87 ) ;
goto V_245;
}
error = F_139 ( V_10 -> V_164 ) ;
if ( error ) {
F_14 ( L_88 ) ;
goto V_245;
}
return 0 ;
V_245:
if ( V_10 -> V_244 )
F_140 ( F_121 ) ;
V_243:
F_141 ( V_10 -> V_164 ) ;
V_242:
F_142 ( V_10 -> V_164 ) ;
V_10 -> V_164 = NULL ;
return error ;
}
static int F_143 ( struct V_9 * V_10 )
{
struct V_246 V_120 ;
int V_52 ;
int V_109 ;
bool V_105 ;
V_52 = F_57 ( V_10 ) ;
if ( V_52 < 0 )
return 0 ;
V_109 = F_65 ( V_10 , V_52 ) ;
if ( V_109 ) {
F_144 ( L_89 ) ;
return 0 ;
}
V_109 = F_55 ( V_10 , & V_105 ) ;
V_10 -> V_108 = ! V_109 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . type = V_247 ;
V_120 . V_121 = V_248 - 1 ;
if ( V_10 -> V_108 )
V_120 . V_121 ++ ;
V_10 -> V_119 = F_145 ( L_90 ,
& V_10 -> V_26 -> V_10 ,
V_10 ,
& V_249 ,
& V_120 ) ;
if ( F_146 ( V_10 -> V_119 ) ) {
V_109 = F_147 ( V_10 -> V_119 ) ;
F_13 ( L_91 ) ;
V_10 -> V_119 = NULL ;
return V_109 ;
}
V_10 -> V_119 -> V_120 . V_52 = V_52 ;
return 0 ;
}
static int F_148 ( struct V_250 * V_26 )
{
struct V_9 * V_10 = F_149 ( V_26 ) ;
F_89 ( V_10 ) ;
if ( V_10 -> V_251 )
F_150 ( & V_10 -> V_26 -> V_10 . V_191 ,
& V_252 ) ;
if ( V_10 -> V_244 ) {
F_140 ( F_121 ) ;
F_151 ( & V_10 -> V_225 ) ;
}
if ( V_10 -> V_164 ) {
F_152 ( V_10 -> V_164 ) ;
F_141 ( V_10 -> V_164 ) ;
}
if ( V_10 -> V_253 ) {
F_153 ( V_10 -> V_253 ) ;
F_154 ( V_10 -> V_253 ) ;
}
F_155 ( V_10 -> V_119 ) ;
if ( V_10 -> V_254 )
F_156 ( & V_10 -> V_53 ) ;
if ( V_10 -> V_255 )
F_156 ( & V_10 -> V_67 ) ;
if ( V_10 -> V_256 )
F_156 ( & V_10 -> V_73 ) ;
if ( V_224 )
V_224 = NULL ;
F_76 ( V_10 ) ;
return 0 ;
}
static const char * F_157 ( T_9 V_27 )
{
if ( F_135 ( V_27 , L_92 ) )
return L_92 ;
if ( F_135 ( V_27 , L_93 ) )
return L_93 ;
return NULL ;
}
static int F_158 ( struct V_250 * V_26 )
{
struct V_9 * V_10 ;
const char * V_257 ;
T_1 V_258 ;
bool V_259 ;
int V_109 = 0 ;
if ( V_224 )
return - V_260 ;
F_14 ( L_94 ,
V_154 ) ;
V_257 = F_157 ( V_26 -> V_27 ) ;
if ( ! V_257 ) {
F_13 ( L_95 ) ;
return - V_66 ;
}
V_10 = F_159 ( sizeof( * V_10 ) , V_143 ) ;
if ( ! V_10 )
return - V_144 ;
V_10 -> V_26 = V_26 ;
V_10 -> V_28 = V_257 ;
V_26 -> V_261 = V_10 ;
F_160 ( & V_26 -> V_10 , V_10 ) ;
if ( F_131 ( V_10 ) )
F_14 ( L_96 ) ;
F_161 ( & V_10 -> V_100 ) ;
V_109 = F_143 ( V_10 ) ;
if ( V_109 )
goto error;
if ( F_48 ( V_10 , & V_259 ) == V_72 && V_259 ) {
V_10 -> V_253 = F_162 ( L_97 ,
& V_26 -> V_10 ,
V_262 ,
& V_263 ,
V_10 ) ;
if ( ! V_10 -> V_253 ) {
F_13 ( L_98 ) ;
V_109 = - V_144 ;
goto error;
}
V_109 = F_163 ( V_10 -> V_253 ) ;
if ( V_109 ) {
F_13 ( L_99 ) ;
F_154 ( V_10 -> V_253 ) ;
goto error;
}
}
if ( F_18 ( V_10 ) ) {
V_10 -> V_53 . V_235 = L_100 ;
V_10 -> V_53 . V_121 = 1 ;
V_10 -> V_53 . V_264 = F_19 ;
V_10 -> V_53 . V_265 = F_21 ;
if ( ! F_164 ( & V_26 -> V_10 , & V_10 -> V_53 ) )
V_10 -> V_254 = 1 ;
}
if ( F_29 ( V_10 ) ) {
V_10 -> V_73 . V_235 = L_101 ;
V_10 -> V_73 . V_121 = 1 ;
V_10 -> V_73 . V_264 = F_31 ;
V_10 -> V_73 . V_265 = F_30 ;
if ( ! F_164 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_73 ) )
V_10 -> V_256 = 1 ;
}
V_10 -> V_198 = F_22 ( V_10 ) ;
if ( V_10 -> V_198 && V_10 -> V_62 == V_171 ) {
V_10 -> V_67 . V_235 = L_102 ;
V_10 -> V_67 . V_121 = 1 ;
V_10 -> V_67 . V_264 = F_26 ;
V_10 -> V_67 . V_265 = F_25 ;
if ( ! F_164 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_67 ) )
V_10 -> V_255 = 1 ;
}
V_109 = F_28 ( V_10 , & V_258 ) ;
V_10 -> V_201 = ! V_109 ;
V_109 = F_32 ( V_10 ) ;
V_10 -> V_203 = ! V_109 ;
V_109 = F_34 ( V_10 , & V_258 ) ;
V_10 -> V_205 = ! V_109 ;
V_109 = F_38 ( V_10 , & V_258 ) ;
V_10 -> V_208 = ! V_109 ;
V_109 = F_40 ( V_10 , & V_258 ) ;
V_10 -> V_210 = ! V_109 ;
V_109 = F_42 ( V_10 , & V_258 ) ;
V_10 -> V_212 = ! V_109 ;
V_109 = F_44 ( V_10 , & V_258 ) ;
V_10 -> V_214 = ! V_109 ;
V_109 = F_46 ( V_10 , & V_258 ) ;
V_10 -> V_216 = ! V_109 ;
V_109 = F_71 ( V_10 , & V_258 ) ;
V_10 -> V_160 = ! V_109 ;
V_109 = F_77 ( V_10 , & V_258 ) ;
V_10 -> V_162 = ! V_109 ;
V_109 = F_165 ( & V_10 -> V_26 -> V_10 . V_191 ,
& V_252 ) ;
if ( V_109 ) {
V_10 -> V_251 = 0 ;
goto error;
}
V_10 -> V_251 = ! V_109 ;
F_87 ( V_10 ) ;
V_224 = V_10 ;
return 0 ;
error:
F_148 ( V_26 ) ;
return V_109 ;
}
static void F_166 ( struct V_250 * V_26 , T_1 V_266 )
{
struct V_9 * V_10 = F_149 ( V_26 ) ;
int V_109 ;
switch ( V_266 ) {
case 0x80 :
F_130 ( V_10 ) ;
break;
case 0x92 :
V_109 = F_167 ( & V_26 -> V_10 . V_191 ,
& V_252 ) ;
if ( V_109 )
F_13 ( L_103 ) ;
break;
case 0x81 :
case 0x82 :
case 0x83 :
case 0x8c :
case 0x8e :
case 0x8f :
case 0x90 :
default:
F_14 ( L_104 , V_266 ) ;
break;
}
}
static int F_168 ( struct V_167 * V_167 )
{
struct V_9 * V_10 = F_149 ( F_169 ( V_167 ) ) ;
T_1 V_55 ;
if ( V_10 -> V_164 )
V_55 = F_6 ( V_10 , V_217 , V_267 ) ;
return 0 ;
}
static int F_170 ( struct V_167 * V_167 )
{
struct V_9 * V_10 = F_149 ( F_169 ( V_167 ) ) ;
int error ;
if ( V_10 -> V_164 ) {
error = F_120 ( V_10 ) ;
if ( error )
F_14 ( L_105 ) ;
}
return 0 ;
}
static int T_10 F_171 ( void )
{
int V_109 ;
if ( F_172 ( V_268 ) )
return - V_66 ;
V_158 = F_173 ( V_269 , V_270 ) ;
if ( ! V_158 ) {
F_13 ( L_106 V_269 L_107 ) ;
return - V_66 ;
}
V_109 = F_174 ( & V_271 ) ;
if ( V_109 ) {
F_13 ( L_108 , V_109 ) ;
F_90 ( V_269 , V_270 ) ;
}
return V_109 ;
}
static void T_11 F_175 ( void )
{
F_176 ( & V_271 ) ;
if ( V_158 )
F_90 ( V_269 , V_270 ) ;
}
