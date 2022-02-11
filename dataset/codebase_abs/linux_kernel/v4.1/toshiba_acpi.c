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
static void F_34 ( struct V_9 * V_10 )
{
T_1 V_11 [ V_12 ] = { V_46 , V_80 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
V_10 -> V_81 = 0 ;
if ( ! F_12 ( V_10 ) )
return;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_26 ) ;
F_15 ( V_10 ) ;
return;
} else if ( V_13 [ 0 ] == V_42 ) {
F_14 ( L_27 ) ;
F_15 ( V_10 ) ;
return;
} else if ( V_13 [ 0 ] == V_72 ) {
V_10 -> V_82 = V_13 [ 4 ] ;
}
V_11 [ 5 ] = V_83 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_26 ) ;
F_15 ( V_10 ) ;
return;
} else if ( V_13 [ 0 ] == V_42 ) {
F_14 ( L_27 ) ;
F_15 ( V_10 ) ;
return;
} else if ( V_13 [ 0 ] == V_72 ) {
V_10 -> V_84 = V_13 [ 2 ] ;
V_10 -> V_81 = 1 ;
}
F_15 ( V_10 ) ;
}
static int F_35 ( struct V_9 * V_10 ,
T_1 * V_85 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_80 , V_85 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_28 ) ;
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
T_1 V_85 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_80 , V_85 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_28 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_27 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_37 ( struct V_9 * V_10 ,
T_1 * V_85 )
{
T_1 V_11 [ V_12 ] = { V_46 , V_80 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
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
* V_85 = V_13 [ 2 ] ;
return 0 ;
}
static int F_38 ( struct V_9 * V_10 ,
T_1 V_85 )
{
T_1 V_11 [ V_12 ] = { V_47 , V_80 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_11 [ 2 ] = V_85 ;
V_11 [ 5 ] = V_83 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_15 ( V_10 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_30 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_42 ) {
F_14 ( L_27 ) ;
return - V_66 ;
} else if ( V_13 [ 0 ] == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_39 ( struct V_9 * V_10 ,
T_1 * V_54 )
{
T_1 V_11 [ V_12 ] = { V_46 , V_80 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_11 [ 5 ] = V_86 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_15 ( V_10 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_31 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_42 ||
V_13 [ 0 ] == V_57 ) {
F_14 ( L_32 ) ;
return - V_66 ;
}
* V_54 = V_13 [ 2 ] ;
return 0 ;
}
static int F_40 ( struct V_9 * V_10 ,
T_1 V_54 )
{
T_1 V_11 [ V_12 ] = { V_47 , V_80 , 0 , 0 , 0 , 0 } ;
T_1 V_13 [ V_12 ] ;
T_2 V_6 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_11 [ 2 ] = V_54 ;
V_11 [ 5 ] = V_86 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_15 ( V_10 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_33 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_42 ) {
F_14 ( L_32 ) ;
return - V_66 ;
} else if ( V_13 [ 0 ] == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_41 ( struct V_9 * V_10 , T_1 * V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_87 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_34 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_35 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_42 ( struct V_9 * V_10 , T_1 V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_87 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_36 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_35 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_43 ( struct V_9 * V_10 , T_1 * V_85 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_88 , V_85 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_37 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_38 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_44 ( struct V_9 * V_10 , T_1 V_85 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_88 , V_85 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_39 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_38 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_45 ( struct V_9 * V_10 , T_1 * V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_89 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_40 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_41 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_46 ( struct V_9 * V_10 , T_1 V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_89 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_42 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_43 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_47 ( struct V_9 * V_10 , T_1 * V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_90 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_44 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_45 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_48 ( struct V_9 * V_10 , T_1 V_54 )
{
T_1 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_90 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_46 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_45 ) ;
return - V_66 ;
} else if ( V_55 == V_57 ) {
return - V_8 ;
}
return 0 ;
}
static int F_49 ( struct V_9 * V_10 ,
T_1 * type )
{
T_1 V_91 = 0x03 ;
T_1 V_92 = 0 ;
T_1 V_55 ;
V_55 = F_11 ( V_10 , V_93 , & V_91 , & V_92 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_47 ) ;
return - V_8 ;
} else if ( V_55 == V_42 ) {
F_14 ( L_48 ) ;
return - V_66 ;
}
* type = V_92 ;
return 0 ;
}
static T_1 F_50 ( struct V_9 * V_10 , bool * V_94 )
{
T_1 V_95 ;
T_1 V_3 , V_96 ;
V_3 = 0 ;
V_96 = 0 ;
V_95 = F_11 ( V_10 , V_97 , & V_3 , & V_96 ) ;
if ( V_95 == V_72 )
* V_94 = ( V_3 & V_98 ) ? true : false ;
return V_95 ;
}
static T_1 F_51 ( struct V_9 * V_10 , bool * V_99 )
{
T_1 V_95 ;
T_1 V_3 , V_96 ;
V_3 = 0 ;
V_96 = 0x0001 ;
V_95 = F_11 ( V_10 , V_97 , & V_3 , & V_96 ) ;
* V_99 = V_3 & V_100 ;
return V_95 ;
}
static int F_52 ( void * V_101 , bool V_102 )
{
struct V_9 * V_10 = V_101 ;
T_1 V_103 , V_104 ;
T_1 V_3 ;
int V_105 ;
bool V_99 ;
V_3 = ( V_102 == false ) ;
F_53 ( & V_10 -> V_106 ) ;
if ( F_51 ( V_10 , & V_99 ) != V_72 ) {
V_105 = - V_8 ;
goto V_13;
}
if ( ! V_99 ) {
V_105 = 0 ;
goto V_13;
}
V_103 = F_10 ( V_10 , V_97 , V_3 , V_107 ) ;
V_104 = F_10 ( V_10 , V_97 , V_3 , V_108 ) ;
if ( V_103 != V_72 || V_104 != V_72 )
V_105 = - V_8 ;
else
V_105 = 0 ;
V_13:
F_54 ( & V_10 -> V_106 ) ;
return V_105 ;
}
static void F_55 ( struct V_109 * V_109 , void * V_101 )
{
bool V_110 ;
bool V_3 ;
T_1 V_95 ;
struct V_9 * V_10 = V_101 ;
F_53 ( & V_10 -> V_106 ) ;
V_95 = F_51 ( V_10 , & V_3 ) ;
if ( V_95 != V_72 ) {
F_54 ( & V_10 -> V_106 ) ;
return;
}
V_110 = V_3 ;
F_54 ( & V_10 -> V_106 ) ;
if ( F_56 ( V_109 , ! V_110 ) )
F_52 ( V_101 , true ) ;
}
static int F_57 ( struct V_9 * V_10 , bool * V_111 )
{
T_1 V_95 ;
T_1 V_6 ;
V_95 = F_8 ( V_10 , V_112 , & V_6 ) ;
* V_111 = ! V_6 ;
return V_95 == V_72 ? 0 : - V_8 ;
}
static int F_58 ( struct V_9 * V_10 , bool V_113 )
{
T_1 V_95 ;
T_1 V_3 = ! V_113 ;
V_95 = F_6 ( V_10 , V_112 , V_3 ) ;
return V_95 == V_72 ? 0 : - V_8 ;
}
static int F_59 ( struct V_9 * V_10 )
{
T_1 V_95 ;
T_1 V_3 ;
int V_52 = 0 ;
if ( V_10 -> V_114 ) {
bool V_111 ;
int V_115 = F_57 ( V_10 , & V_111 ) ;
if ( V_115 )
return V_115 ;
if ( V_111 )
return 0 ;
V_52 ++ ;
}
V_95 = F_8 ( V_10 , V_116 , & V_3 ) ;
if ( V_95 == V_72 )
return V_52 + ( V_3 >> V_117 ) ;
return - V_8 ;
}
static int F_60 ( struct V_118 * V_119 )
{
struct V_9 * V_10 = F_61 ( V_119 ) ;
return F_59 ( V_10 ) ;
}
static int F_62 ( struct V_120 * V_121 , void * V_122 )
{
struct V_9 * V_10 = V_121 -> V_123 ;
int V_3 ;
int V_124 ;
if ( ! V_10 -> V_125 )
return - V_66 ;
V_124 = V_10 -> V_125 -> V_126 . V_127 + 1 ;
V_3 = F_60 ( V_10 -> V_125 ) ;
if ( V_3 >= 0 ) {
F_63 ( V_121 , L_49 , V_3 ) ;
F_63 ( V_121 , L_50 , V_124 ) ;
return 0 ;
}
F_13 ( L_51 ) ;
return - V_8 ;
}
static int F_64 ( struct V_128 * V_128 , struct V_129 * V_129 )
{
return F_65 ( V_129 , F_62 , F_66 ( V_128 ) ) ;
}
static int F_67 ( struct V_9 * V_10 , int V_3 )
{
T_1 V_95 ;
if ( V_10 -> V_114 ) {
bool V_113 = ! V_3 ;
int V_115 = F_58 ( V_10 , V_113 ) ;
if ( V_115 )
return V_115 ;
if ( V_3 )
V_3 -- ;
}
V_3 = V_3 << V_117 ;
V_95 = F_6 ( V_10 , V_116 , V_3 ) ;
return V_95 == V_72 ? 0 : - V_8 ;
}
static int F_68 ( struct V_118 * V_119 )
{
struct V_9 * V_10 = F_61 ( V_119 ) ;
return F_67 ( V_10 , V_119 -> V_126 . V_52 ) ;
}
static T_3 F_69 ( struct V_129 * V_129 , const char T_4 * V_130 ,
T_5 V_22 , T_6 * V_131 )
{
struct V_9 * V_10 = F_66 ( F_70 ( V_129 ) ) ;
char V_132 [ 42 ] ;
T_5 V_133 ;
int V_3 ;
int V_115 ;
int V_124 = V_10 -> V_125 -> V_126 . V_127 + 1 ;
V_133 = F_71 ( V_22 , sizeof( V_132 ) - 1 ) ;
if ( F_72 ( V_132 , V_130 , V_133 ) )
return - V_134 ;
V_132 [ V_133 ] = '\0' ;
if ( sscanf ( V_132 , L_52 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 < V_124 ) {
V_115 = F_67 ( V_10 , V_3 ) ;
if ( V_115 == 0 )
V_115 = V_22 ;
} else {
V_115 = - V_135 ;
}
return V_115 ;
}
static int F_73 ( struct V_9 * V_10 , T_1 * V_6 )
{
T_1 V_95 ;
V_95 = F_8 ( V_10 , V_136 , V_6 ) ;
return V_95 == V_72 ? 0 : - V_8 ;
}
static int F_74 ( struct V_120 * V_121 , void * V_122 )
{
struct V_9 * V_10 = V_121 -> V_123 ;
T_1 V_3 ;
int V_115 ;
V_115 = F_73 ( V_10 , & V_3 ) ;
if ( ! V_115 ) {
int V_137 = ( V_3 & V_138 ) ? 1 : 0 ;
int V_139 = ( V_3 & V_140 ) ? 1 : 0 ;
int V_141 = ( V_3 & V_142 ) ? 1 : 0 ;
F_63 ( V_121 , L_53 , V_137 ) ;
F_63 ( V_121 , L_54 , V_139 ) ;
F_63 ( V_121 , L_55 , V_141 ) ;
}
return V_115 ;
}
static int F_75 ( struct V_128 * V_128 , struct V_129 * V_129 )
{
return F_65 ( V_129 , F_74 , F_66 ( V_128 ) ) ;
}
static T_3 F_76 ( struct V_129 * V_129 , const char T_4 * V_130 ,
T_5 V_22 , T_6 * V_131 )
{
struct V_9 * V_10 = F_66 ( F_70 ( V_129 ) ) ;
char * V_132 , * V_143 ;
int V_115 ;
int V_3 ;
int V_144 = V_22 ;
int V_145 = - 1 ;
int V_146 = - 1 ;
int V_147 = - 1 ;
T_1 V_148 ;
V_132 = F_77 ( V_22 + 1 , V_149 ) ;
if ( ! V_132 )
return - V_150 ;
if ( F_72 ( V_132 , V_130 , V_22 ) ) {
F_78 ( V_132 ) ;
return - V_134 ;
}
V_132 [ V_22 ] = '\0' ;
V_143 = V_132 ;
while ( V_144 ) {
if ( sscanf ( V_143 , L_56 , & V_3 ) == 1 )
V_145 = V_3 & 1 ;
else if ( sscanf ( V_143 , L_57 , & V_3 ) == 1 )
V_146 = V_3 & 1 ;
else if ( sscanf ( V_143 , L_58 , & V_3 ) == 1 )
V_147 = V_3 & 1 ;
do {
++ V_143 ;
-- V_144 ;
} while ( V_144 && * ( V_143 - 1 ) != ';' );
}
F_78 ( V_132 ) ;
V_115 = F_73 ( V_10 , & V_148 ) ;
if ( ! V_115 ) {
unsigned int V_151 = V_148 ;
if ( V_145 != - 1 )
F_1 ( & V_151 , V_138 , V_145 ) ;
if ( V_146 != - 1 )
F_1 ( & V_151 , V_140 , V_146 ) ;
if ( V_147 != - 1 )
F_1 ( & V_151 , V_142 , V_147 ) ;
if ( V_151 != V_148 )
V_115 = F_2 ( V_152 , V_151 ) ;
}
return V_115 ? V_115 : V_22 ;
}
static int F_79 ( struct V_9 * V_10 , T_1 * V_6 )
{
T_1 V_95 ;
V_95 = F_8 ( V_10 , V_153 , V_6 ) ;
return V_95 == V_72 ? 0 : - V_8 ;
}
static int F_80 ( struct V_120 * V_121 , void * V_122 )
{
struct V_9 * V_10 = V_121 -> V_123 ;
int V_115 ;
T_1 V_3 ;
V_115 = F_79 ( V_10 , & V_3 ) ;
if ( ! V_115 ) {
F_63 ( V_121 , L_59 , ( V_3 > 0 ) ) ;
F_63 ( V_121 , L_60 , V_10 -> V_154 ) ;
}
return V_115 ;
}
static int F_81 ( struct V_128 * V_128 , struct V_129 * V_129 )
{
return F_65 ( V_129 , F_80 , F_66 ( V_128 ) ) ;
}
static T_3 F_82 ( struct V_129 * V_129 , const char T_4 * V_130 ,
T_5 V_22 , T_6 * V_131 )
{
struct V_9 * V_10 = F_66 ( F_70 ( V_129 ) ) ;
char V_132 [ 42 ] ;
T_5 V_133 ;
int V_3 ;
T_1 V_95 ;
V_133 = F_71 ( V_22 , sizeof( V_132 ) - 1 ) ;
if ( F_72 ( V_132 , V_130 , V_133 ) )
return - V_134 ;
V_132 [ V_133 ] = '\0' ;
if ( sscanf ( V_132 , L_61 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 <= 1 ) {
V_95 = F_6 ( V_10 , V_153 , V_3 ) ;
if ( V_95 == V_72 )
V_10 -> V_154 = V_3 ;
else
return - V_8 ;
} else {
return - V_135 ;
}
return V_22 ;
}
static int F_83 ( struct V_120 * V_121 , void * V_122 )
{
struct V_9 * V_10 = V_121 -> V_123 ;
T_1 V_95 ;
T_1 V_3 ;
if ( ! V_10 -> V_155 && V_10 -> V_156 ) {
V_95 = F_8 ( V_10 , V_157 , & V_3 ) ;
if ( V_95 == V_72 ) {
V_10 -> V_155 = 1 ;
V_10 -> V_158 = V_3 ;
} else if ( V_95 == V_159 ) {
} else if ( V_95 == V_42 ) {
V_95 = F_6 ( V_10 , V_157 , 1 ) ;
F_84 ( L_62 ) ;
} else {
F_13 ( L_63 ) ;
return - V_8 ;
}
}
F_63 ( V_121 , L_64 , V_10 -> V_155 ) ;
F_63 ( V_121 , L_65 , V_10 -> V_158 ) ;
return 0 ;
}
static int F_85 ( struct V_128 * V_128 , struct V_129 * V_129 )
{
return F_65 ( V_129 , F_83 , F_66 ( V_128 ) ) ;
}
static T_3 F_86 ( struct V_129 * V_129 , const char T_4 * V_130 ,
T_5 V_22 , T_6 * V_131 )
{
struct V_9 * V_10 = F_66 ( F_70 ( V_129 ) ) ;
char V_132 [ 42 ] ;
T_5 V_133 ;
int V_3 ;
V_133 = F_71 ( V_22 , sizeof( V_132 ) - 1 ) ;
if ( F_72 ( V_132 , V_130 , V_133 ) )
return - V_134 ;
V_132 [ V_133 ] = '\0' ;
if ( sscanf ( V_132 , L_66 , & V_3 ) == 1 && V_3 == 0 )
V_10 -> V_155 = 0 ;
else
return - V_135 ;
return V_22 ;
}
static int F_87 ( struct V_120 * V_121 , void * V_122 )
{
F_63 ( V_121 , L_67 , V_160 ) ;
F_63 ( V_121 , L_68 , V_161 ) ;
return 0 ;
}
static int F_88 ( struct V_128 * V_128 , struct V_129 * V_129 )
{
return F_65 ( V_129 , F_87 , F_66 ( V_128 ) ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
if ( V_10 -> V_125 )
F_90 ( L_69 , V_162 | V_163 , V_164 ,
& V_165 , V_10 ) ;
if ( V_10 -> V_166 )
F_90 ( L_70 , V_162 | V_163 , V_164 ,
& V_167 , V_10 ) ;
if ( V_10 -> V_168 )
F_90 ( L_71 , V_162 | V_163 , V_164 ,
& V_169 , V_10 ) ;
if ( V_10 -> V_170 )
F_90 ( L_72 , V_162 | V_163 , V_164 ,
& V_171 , V_10 ) ;
F_90 ( L_73 , V_162 , V_164 ,
& V_172 , V_10 ) ;
}
static void F_91 ( struct V_9 * V_10 )
{
if ( V_10 -> V_125 )
F_92 ( L_69 , V_164 ) ;
if ( V_10 -> V_166 )
F_92 ( L_70 , V_164 ) ;
if ( V_10 -> V_168 )
F_92 ( L_71 , V_164 ) ;
if ( V_10 -> V_170 )
F_92 ( L_72 , V_164 ) ;
F_92 ( L_73 , V_164 ) ;
}
static T_3 F_93 ( struct V_173 * V_10 ,
struct V_174 * V_175 , char * V_130 )
{
return sprintf ( V_130 , L_74 , V_160 ) ;
}
static T_3 F_94 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
const char * V_130 , T_5 V_22 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 V_55 ;
int V_54 ;
int V_115 ;
V_115 = F_96 ( V_130 , 0 , & V_54 ) ;
if ( V_115 )
return V_115 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_135 ;
V_55 = F_6 ( V_176 , V_153 , V_54 ) ;
if ( V_55 == V_34 )
return - V_8 ;
else if ( V_55 == V_42 )
return - V_66 ;
return V_22 ;
}
static T_3 F_97 ( struct V_173 * V_10 ,
struct V_174 * V_175 , char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 V_3 ;
int V_115 ;
V_115 = F_79 ( V_176 , & V_3 ) ;
if ( V_115 )
return V_115 ;
return sprintf ( V_130 , L_75 , V_3 ) ;
}
static T_3 F_98 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
const char * V_130 , T_5 V_22 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
int V_85 ;
int time ;
int V_115 ;
V_115 = F_96 ( V_130 , 0 , & V_85 ) ;
if ( V_115 )
return V_115 ;
if ( V_176 -> V_61 == 1 ) {
if ( V_85 != V_177 && V_85 != V_178 )
return - V_135 ;
} else if ( V_176 -> V_61 == 2 ) {
if ( V_85 != V_178 && V_85 != V_179 &&
V_85 != V_180 )
return - V_135 ;
}
if ( V_176 -> V_62 != V_85 ) {
time = V_176 -> V_64 << V_65 ;
if ( V_176 -> V_61 == 1 ) {
time |= V_176 -> V_62 ;
} else if ( V_176 -> V_61 == 2 ) {
time |= V_85 ;
}
V_115 = F_23 ( V_176 , time ) ;
if ( V_115 )
return V_115 ;
V_176 -> V_62 = V_85 ;
}
return V_22 ;
}
static T_3 F_99 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 time ;
if ( F_24 ( V_176 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_130 , L_76 , time & V_63 ) ;
}
static T_3 F_100 ( struct V_173 * V_10 ,
struct V_174 * V_175 , char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
return sprintf ( V_130 , L_75 , V_176 -> V_61 ) ;
}
static T_3 F_101 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
if ( V_176 -> V_61 == 1 )
return sprintf ( V_130 , L_77 ,
V_177 , V_178 ) ;
return sprintf ( V_130 , L_78 ,
V_178 , V_179 , V_180 ) ;
}
static T_3 F_102 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
const char * V_130 , T_5 V_22 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
int time ;
int V_115 ;
V_115 = F_96 ( V_130 , 0 , & time ) ;
if ( V_115 )
return V_115 ;
if ( V_176 -> V_61 == 1 ) {
if ( time < 0 || time > 60 )
return - V_135 ;
} else if ( V_176 -> V_61 == 2 ) {
if ( time < 1 || time > 60 )
return - V_135 ;
}
if ( V_176 -> V_64 != time ) {
time = time << V_65 ;
if ( V_176 -> V_61 == 1 )
time |= V_177 ;
else if ( V_176 -> V_61 == 2 )
time |= V_178 ;
V_115 = F_23 ( V_176 , time ) ;
if ( V_115 )
return V_115 ;
V_176 -> V_64 = time >> V_65 ;
}
return V_22 ;
}
static T_3 F_103 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 time ;
if ( F_24 ( V_176 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_130 , L_76 , time >> V_65 ) ;
}
static T_3 F_104 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
const char * V_130 , T_5 V_22 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
int V_54 ;
int V_115 ;
V_115 = F_96 ( V_130 , 0 , & V_54 ) ;
if ( V_115 )
return V_115 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_135 ;
V_115 = F_27 ( V_176 , V_54 ) ;
if ( V_115 )
return V_115 ;
return V_22 ;
}
static T_3 F_105 ( struct V_173 * V_10 ,
struct V_174 * V_175 , char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 V_54 ;
int V_115 ;
V_115 = F_28 ( V_176 , & V_54 ) ;
if ( V_115 < 0 )
return V_115 ;
return sprintf ( V_130 , L_76 , V_54 ) ;
}
static T_3 F_106 ( struct V_173 * V_10 ,
struct V_174 * V_175 , char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 V_181 , V_182 , V_183 ;
T_7 V_184 , V_185 , V_78 ;
int V_115 ;
V_181 = V_182 = 0 ;
V_115 = F_33 ( V_176 , & V_181 , & V_182 ) ;
if ( V_115 < 0 )
return V_115 ;
V_184 = V_181 & V_186 ;
V_183 = V_181 >> V_65 ;
V_185 = V_183 & V_186 ;
V_78 = V_182 & V_186 ;
return sprintf ( V_130 , L_79 , V_184 , V_185 , V_78 ) ;
}
static T_3 F_107 ( struct V_173 * V_10 ,
struct V_174 * V_175 , char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 V_85 ;
int V_115 ;
V_115 = F_35 ( V_176 , & V_85 ) ;
if ( V_115 < 0 )
return V_115 ;
return sprintf ( V_130 , L_80 , V_85 & V_187 ) ;
}
static T_3 F_108 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
const char * V_130 , T_5 V_22 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 V_85 ;
int V_54 ;
int V_115 ;
V_115 = F_96 ( V_130 , 0 , & V_54 ) ;
if ( V_115 )
return V_115 ;
if ( V_54 != 0 && V_54 != 1 && V_54 != 2 && V_54 != 3 )
return - V_135 ;
V_85 = V_176 -> V_82 ;
if ( V_54 == 0 )
V_85 |= V_188 ;
else if ( V_54 == 1 )
V_85 |= V_189 ;
else if ( V_54 == 2 )
V_85 |= V_190 ;
else if ( V_54 == 3 )
V_85 |= V_191 ;
V_115 = F_36 ( V_176 , V_85 ) ;
if ( V_115 )
return V_115 ;
return V_22 ;
}
static T_3 F_109 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 V_54 ;
int V_192 ;
int V_6 ;
int V_115 ;
int V_183 ;
V_115 = F_37 ( V_176 , & V_54 ) ;
if ( V_115 < 0 )
return V_115 ;
V_183 = V_54 & V_193 ;
V_6 = ( V_183 == 0x4 ) ? 1 : 0 ;
V_192 = V_54 >> V_65 ;
return sprintf ( V_130 , L_81 , V_6 , V_192 ) ;
}
static T_3 F_110 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
const char * V_130 , T_5 V_22 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 V_6 ;
int V_3 ;
int V_115 ;
int V_183 ;
V_115 = F_96 ( V_130 , 0 , & V_3 ) ;
if ( V_115 )
return V_115 ;
if ( V_3 < 0 || V_3 > 100 )
return - V_135 ;
if ( V_3 == 0 ) {
V_183 = V_176 -> V_84 << V_65 ;
V_6 = V_183 | V_194 ;
} else {
V_183 = V_3 << V_65 ;
V_6 = V_183 | V_195 ;
}
V_115 = F_38 ( V_176 , V_6 ) ;
if ( V_115 < 0 )
return V_115 ;
V_176 -> V_84 = V_6 >> V_65 ;
return V_22 ;
}
static T_3 F_111 ( struct V_173 * V_10 ,
struct V_174 * V_175 , char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 V_54 ;
int V_115 ;
V_115 = F_39 ( V_176 , & V_54 ) ;
if ( V_115 < 0 )
return V_115 ;
return sprintf ( V_130 , L_75 , V_54 ) ;
}
static T_3 F_112 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
const char * V_130 , T_5 V_22 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
int V_54 ;
int V_115 ;
V_115 = F_96 ( V_130 , 0 , & V_54 ) ;
if ( V_115 )
return V_115 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_135 ;
V_115 = F_40 ( V_176 , V_54 ) ;
if ( V_115 )
return V_115 ;
return V_22 ;
}
static T_3 F_113 ( struct V_173 * V_10 ,
struct V_174 * V_175 , char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 V_54 ;
int V_115 ;
V_115 = F_41 ( V_176 , & V_54 ) ;
if ( V_115 < 0 )
return V_115 ;
return sprintf ( V_130 , L_75 , V_54 ) ;
}
static T_3 F_114 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
const char * V_130 , T_5 V_22 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
int V_54 ;
int V_115 ;
V_115 = F_96 ( V_130 , 0 , & V_54 ) ;
if ( V_115 )
return V_115 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_135 ;
V_115 = F_42 ( V_176 , V_54 ) ;
if ( V_115 )
return V_115 ;
return V_22 ;
}
static T_3 F_115 ( struct V_173 * V_10 ,
struct V_174 * V_175 , char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
int V_85 ;
int V_115 ;
V_115 = F_43 ( V_176 , & V_85 ) ;
if ( V_115 < 0 )
return V_115 ;
return sprintf ( V_130 , L_75 , V_85 ) ;
}
static T_3 F_116 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
const char * V_130 , T_5 V_22 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
int V_85 ;
int V_115 ;
V_115 = F_96 ( V_130 , 0 , & V_85 ) ;
if ( V_115 )
return V_115 ;
if ( V_85 != 0 && V_85 != 1 )
return - V_135 ;
V_115 = F_44 ( V_176 , V_85 ) ;
if ( V_115 )
return V_115 ;
F_14 ( L_82 ) ;
return V_22 ;
}
static T_3 F_117 ( struct V_173 * V_10 ,
struct V_174 * V_175 , char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 V_54 ;
int V_115 ;
V_115 = F_45 ( V_176 , & V_54 ) ;
if ( V_115 < 0 )
return V_115 ;
return sprintf ( V_130 , L_75 , V_54 ) ;
}
static T_3 F_118 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
const char * V_130 , T_5 V_22 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
int V_54 ;
int V_115 ;
V_115 = F_96 ( V_130 , 0 , & V_54 ) ;
if ( V_115 )
return V_115 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_135 ;
V_115 = F_46 ( V_176 , V_54 ) ;
if ( V_115 )
return V_115 ;
F_14 ( L_83 ) ;
return V_22 ;
}
static T_3 F_119 ( struct V_173 * V_10 ,
struct V_174 * V_175 , char * V_130 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
T_1 V_54 ;
int V_115 ;
V_115 = F_47 ( V_176 , & V_54 ) ;
if ( V_115 < 0 )
return V_115 ;
return sprintf ( V_130 , L_75 , V_54 ) ;
}
static T_3 F_120 ( struct V_173 * V_10 ,
struct V_174 * V_175 ,
const char * V_130 , T_5 V_22 )
{
struct V_9 * V_176 = F_95 ( V_10 ) ;
int V_54 ;
int V_115 ;
V_115 = F_96 ( V_130 , 0 , & V_54 ) ;
if ( V_115 )
return V_115 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_135 ;
V_115 = F_48 ( V_176 , V_54 ) ;
if ( V_115 )
return V_115 ;
F_14 ( L_84 ) ;
return V_22 ;
}
static T_8 F_121 ( struct V_196 * V_197 ,
struct V_198 * V_175 , int V_199 )
{
struct V_173 * V_10 = F_20 ( V_197 , struct V_173 , V_197 ) ;
struct V_9 * V_200 = F_95 ( V_10 ) ;
bool V_201 = true ;
if ( V_175 == & V_202 . V_175 )
V_201 = ( V_200 -> V_168 ) ? true : false ;
else if ( V_175 == & V_203 . V_175 )
V_201 = ( V_200 -> V_204 ) ? true : false ;
else if ( V_175 == & V_205 . V_175 )
V_201 = ( V_200 -> V_62 == V_178 ) ? true : false ;
else if ( V_175 == & V_206 . V_175 )
V_201 = ( V_200 -> V_207 ) ? true : false ;
else if ( V_175 == & V_208 . V_175 )
V_201 = ( V_200 -> V_209 ) ? true : false ;
else if ( V_175 == & V_210 . V_175 )
V_201 = ( V_200 -> V_81 ) ? true : false ;
else if ( V_175 == & V_211 . V_175 )
V_201 = ( V_200 -> V_81 ) ? true : false ;
else if ( V_175 == & V_212 . V_175 )
V_201 = ( V_200 -> V_213 ) ? true : false ;
else if ( V_175 == & V_214 . V_175 )
V_201 = ( V_200 -> V_215 ) ? true : false ;
else if ( V_175 == & V_216 . V_175 )
V_201 = ( V_200 -> V_217 ) ? true : false ;
else if ( V_175 == & V_218 . V_175 )
V_201 = ( V_200 -> V_219 ) ? true : false ;
else if ( V_175 == & V_220 . V_175 )
V_201 = ( V_200 -> V_221 ) ? true : false ;
return V_201 ? V_175 -> V_85 : 0 ;
}
static int F_122 ( struct V_9 * V_10 )
{
T_2 V_6 ;
T_1 V_55 ;
V_6 = F_5 ( V_10 -> V_26 -> V_27 ,
L_85 , NULL , NULL ) ;
if ( F_9 ( V_6 ) )
return - V_66 ;
V_55 = F_6 ( V_10 , V_222 , V_223 ) ;
if ( V_55 == V_34 )
return - V_8 ;
else if ( V_55 == V_42 )
return - V_66 ;
return 0 ;
}
static void F_123 ( struct V_9 * V_10 )
{
T_1 V_55 ;
V_55 = F_6 ( V_10 , V_222 ,
V_224 ) ;
if ( V_55 != V_72 )
F_13 ( L_86 ) ;
}
static bool F_124 ( unsigned char V_101 , unsigned char V_225 ,
struct V_226 * V_227 )
{
if ( V_225 & V_228 )
return false ;
if ( F_125 ( V_101 == 0xe0 ) )
return false ;
if ( ( V_101 & 0x7f ) == V_229 ) {
F_126 ( & V_230 -> V_231 ) ;
return true ;
}
return false ;
}
static void F_127 ( struct V_232 * V_233 )
{
T_9 V_234 = F_128 () ;
T_2 V_6 ;
if ( ! V_234 )
return;
V_6 = F_5 ( V_234 , L_87 , NULL , NULL ) ;
if ( F_9 ( V_6 ) )
F_13 ( L_88 ) ;
}
static int F_129 ( struct V_9 * V_10 )
{
unsigned long long V_3 ;
T_2 V_6 ;
V_6 = F_130 ( V_10 -> V_26 -> V_27 , L_89 ,
NULL , & V_3 ) ;
if ( F_9 ( V_6 ) ) {
F_13 ( L_90 ) ;
return - V_8 ;
}
return V_3 ;
}
static void F_131 ( struct V_9 * V_10 ,
int V_235 )
{
if ( V_235 == 0x100 )
return;
if ( V_235 & 0x80 )
return;
if ( ! F_132 ( V_10 -> V_170 , V_235 , 1 , true ) )
F_14 ( L_91 , V_235 ) ;
}
static void F_133 ( struct V_9 * V_10 )
{
T_1 V_95 , V_3 ;
int V_236 = 3 ;
int V_235 ;
if ( V_10 -> V_237 ) {
V_235 = F_129 ( V_10 ) ;
if ( V_235 < 0 )
F_13 ( L_92 ) ;
else if ( V_235 != 0 )
F_131 ( V_10 , V_235 ) ;
} else if ( V_10 -> V_156 ) {
do {
V_95 = F_8 ( V_10 , V_157 , & V_3 ) ;
switch ( V_95 ) {
case V_72 :
F_131 ( V_10 , ( int ) V_3 ) ;
break;
case V_42 :
V_95 =
F_6 ( V_10 , V_157 , 1 ) ;
F_84 ( L_62 ) ;
default:
V_236 -- ;
break;
}
} while ( V_236 && V_95 != V_159 );
}
}
static int F_134 ( struct V_9 * V_10 )
{
const struct V_238 * V_239 = V_240 ;
T_9 V_234 ;
T_1 V_241 ;
T_1 V_95 ;
int error ;
error = F_122 ( V_10 ) ;
if ( error )
return error ;
error = F_49 ( V_10 , & V_241 ) ;
if ( error ) {
F_13 ( L_93 ) ;
return error ;
}
V_10 -> V_242 = V_241 ;
V_10 -> V_170 = F_135 () ;
if ( ! V_10 -> V_170 )
return - V_150 ;
V_10 -> V_170 -> V_243 = L_94 ;
V_10 -> V_170 -> V_244 = L_95 ;
V_10 -> V_170 -> V_245 . V_246 = V_247 ;
if ( V_241 == V_248 ||
! V_10 -> V_217 )
V_239 = V_240 ;
else if ( V_241 == V_249 ||
V_10 -> V_217 )
V_239 = V_250 ;
else
F_14 ( L_96 , V_241 ) ;
error = F_136 ( V_10 -> V_170 , V_239 , NULL ) ;
if ( error )
goto V_251;
V_234 = F_128 () ;
if ( V_234 && F_137 ( V_234 , L_87 ) ) {
F_138 ( & V_10 -> V_231 , F_127 ) ;
error = F_139 ( F_124 ) ;
if ( error ) {
F_13 ( L_97 ) ;
goto V_252;
}
V_10 -> V_253 = 1 ;
}
if ( F_137 ( V_10 -> V_26 -> V_27 , L_89 ) )
V_10 -> V_237 = 1 ;
else {
V_95 = F_6 ( V_10 , V_157 , 1 ) ;
if ( V_95 == V_72 )
V_10 -> V_156 = 1 ;
}
if ( ! V_10 -> V_237 && ! V_10 -> V_156 ) {
F_140 ( L_98 ) ;
goto V_254;
}
error = F_141 ( V_10 -> V_170 ) ;
if ( error ) {
F_14 ( L_99 ) ;
goto V_254;
}
return 0 ;
V_254:
if ( V_10 -> V_253 )
F_142 ( F_124 ) ;
V_252:
F_143 ( V_10 -> V_170 ) ;
V_251:
F_144 ( V_10 -> V_170 ) ;
V_10 -> V_170 = NULL ;
return error ;
}
static int F_145 ( struct V_9 * V_10 )
{
struct V_255 V_126 ;
int V_52 ;
int V_115 ;
bool V_111 ;
V_52 = F_59 ( V_10 ) ;
if ( V_52 < 0 )
return 0 ;
V_115 = F_67 ( V_10 , V_52 ) ;
if ( V_115 ) {
F_146 ( L_100 ) ;
return 0 ;
}
V_115 = F_57 ( V_10 , & V_111 ) ;
V_10 -> V_114 = ! V_115 ;
if ( V_10 -> V_114 ||
F_147 ( V_256 ) )
F_148 () ;
if ( F_149 () )
return 0 ;
F_150 () ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . type = V_257 ;
V_126 . V_127 = V_258 - 1 ;
if ( V_10 -> V_114 )
V_126 . V_127 ++ ;
V_10 -> V_125 = F_151 ( L_101 ,
& V_10 -> V_26 -> V_10 ,
V_10 ,
& V_259 ,
& V_126 ) ;
if ( F_152 ( V_10 -> V_125 ) ) {
V_115 = F_153 ( V_10 -> V_125 ) ;
F_13 ( L_102 ) ;
V_10 -> V_125 = NULL ;
return V_115 ;
}
V_10 -> V_125 -> V_126 . V_52 = V_52 ;
return 0 ;
}
static int F_154 ( struct V_260 * V_26 )
{
struct V_9 * V_10 = F_155 ( V_26 ) ;
F_91 ( V_10 ) ;
if ( V_10 -> V_261 )
F_156 ( & V_10 -> V_26 -> V_10 . V_197 ,
& V_262 ) ;
if ( V_10 -> V_253 ) {
F_142 ( F_124 ) ;
F_157 ( & V_10 -> V_231 ) ;
}
if ( V_10 -> V_170 ) {
F_158 ( V_10 -> V_170 ) ;
F_143 ( V_10 -> V_170 ) ;
}
if ( V_10 -> V_263 ) {
F_159 ( V_10 -> V_263 ) ;
F_160 ( V_10 -> V_263 ) ;
}
F_161 ( V_10 -> V_125 ) ;
if ( V_10 -> V_264 )
F_162 ( & V_10 -> V_53 ) ;
if ( V_10 -> V_265 )
F_162 ( & V_10 -> V_67 ) ;
if ( V_10 -> V_266 )
F_162 ( & V_10 -> V_73 ) ;
if ( V_230 )
V_230 = NULL ;
F_78 ( V_10 ) ;
return 0 ;
}
static const char * F_163 ( T_9 V_27 )
{
if ( F_137 ( V_27 , L_103 ) )
return L_103 ;
if ( F_137 ( V_27 , L_104 ) )
return L_104 ;
return NULL ;
}
static int F_164 ( struct V_260 * V_26 )
{
struct V_9 * V_10 ;
const char * V_267 ;
T_1 V_268 ;
T_1 V_269 ;
bool V_270 ;
int V_115 = 0 ;
if ( V_230 )
return - V_271 ;
F_14 ( L_105 ,
V_160 ) ;
V_267 = F_163 ( V_26 -> V_27 ) ;
if ( ! V_267 ) {
F_13 ( L_106 ) ;
return - V_66 ;
}
V_10 = F_165 ( sizeof( * V_10 ) , V_149 ) ;
if ( ! V_10 )
return - V_150 ;
V_10 -> V_26 = V_26 ;
V_10 -> V_28 = V_267 ;
V_26 -> V_272 = V_10 ;
F_166 ( & V_26 -> V_10 , V_10 ) ;
V_115 = F_43 ( V_10 , & V_268 ) ;
V_10 -> V_217 = ! V_115 ;
if ( F_134 ( V_10 ) )
F_14 ( L_107 ) ;
F_167 ( & V_10 -> V_106 ) ;
V_115 = F_145 ( V_10 ) ;
if ( V_115 )
goto error;
if ( F_50 ( V_10 , & V_270 ) == V_72 && V_270 ) {
V_10 -> V_263 = F_168 ( L_108 ,
& V_26 -> V_10 ,
V_273 ,
& V_274 ,
V_10 ) ;
if ( ! V_10 -> V_263 ) {
F_13 ( L_109 ) ;
V_115 = - V_150 ;
goto error;
}
V_115 = F_169 ( V_10 -> V_263 ) ;
if ( V_115 ) {
F_13 ( L_110 ) ;
F_160 ( V_10 -> V_263 ) ;
goto error;
}
}
if ( F_18 ( V_10 ) ) {
V_10 -> V_53 . V_243 = L_111 ;
V_10 -> V_53 . V_127 = 1 ;
V_10 -> V_53 . V_275 = F_19 ;
V_10 -> V_53 . V_276 = F_21 ;
if ( ! F_170 ( & V_26 -> V_10 , & V_10 -> V_53 ) )
V_10 -> V_264 = 1 ;
}
if ( F_29 ( V_10 ) ) {
V_10 -> V_73 . V_243 = L_112 ;
V_10 -> V_73 . V_127 = 1 ;
V_10 -> V_73 . V_275 = F_31 ;
V_10 -> V_73 . V_276 = F_30 ;
if ( ! F_170 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_73 ) )
V_10 -> V_266 = 1 ;
}
V_10 -> V_204 = F_22 ( V_10 ) ;
if ( V_10 -> V_204 && V_10 -> V_62 == V_177 ) {
V_10 -> V_67 . V_243 = L_113 ;
V_10 -> V_67 . V_127 = 1 ;
V_10 -> V_67 . V_275 = F_26 ;
V_10 -> V_67 . V_276 = F_25 ;
if ( ! F_170 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_67 ) )
V_10 -> V_265 = 1 ;
}
V_115 = F_28 ( V_10 , & V_269 ) ;
V_10 -> V_207 = ! V_115 ;
V_115 = F_32 ( V_10 ) ;
V_10 -> V_209 = ! V_115 ;
F_34 ( V_10 ) ;
V_115 = F_39 ( V_10 , & V_269 ) ;
V_10 -> V_213 = ! V_115 ;
V_115 = F_41 ( V_10 , & V_269 ) ;
V_10 -> V_215 = ! V_115 ;
V_115 = F_45 ( V_10 , & V_269 ) ;
V_10 -> V_219 = ! V_115 ;
V_115 = F_47 ( V_10 , & V_269 ) ;
V_10 -> V_221 = ! V_115 ;
V_115 = F_73 ( V_10 , & V_269 ) ;
V_10 -> V_166 = ! V_115 ;
V_115 = F_79 ( V_10 , & V_269 ) ;
V_10 -> V_168 = ! V_115 ;
if ( V_10 -> V_217 && V_268 )
F_123 ( V_10 ) ;
V_115 = F_171 ( & V_10 -> V_26 -> V_10 . V_197 ,
& V_262 ) ;
if ( V_115 ) {
V_10 -> V_261 = 0 ;
goto error;
}
V_10 -> V_261 = ! V_115 ;
F_89 ( V_10 ) ;
V_230 = V_10 ;
return 0 ;
error:
F_154 ( V_26 ) ;
return V_115 ;
}
static void F_172 ( struct V_260 * V_26 , T_1 V_277 )
{
struct V_9 * V_10 = F_155 ( V_26 ) ;
int V_115 ;
switch ( V_277 ) {
case 0x80 :
F_133 ( V_10 ) ;
break;
case 0x81 :
case 0x82 :
case 0x83 :
F_14 ( L_114 , V_277 ) ;
break;
case 0x88 :
F_14 ( L_115 ) ;
break;
case 0x8f :
case 0x90 :
break;
case 0x8c :
case 0x8b :
F_14 ( L_116 , V_277 ) ;
break;
case 0x92 :
V_115 = F_173 ( & V_26 -> V_10 . V_197 ,
& V_262 ) ;
if ( V_115 )
F_13 ( L_117 ) ;
break;
case 0x85 :
case 0x8d :
case 0x8e :
case 0x94 :
case 0x95 :
default:
F_14 ( L_118 , V_277 ) ;
break;
}
F_174 ( V_26 -> V_278 . V_279 ,
F_175 ( & V_26 -> V_10 ) ,
V_277 , 0 ) ;
}
static int F_176 ( struct V_173 * V_173 )
{
struct V_9 * V_10 = F_155 ( F_177 ( V_173 ) ) ;
T_1 V_55 ;
if ( V_10 -> V_170 )
V_55 = F_6 ( V_10 , V_222 , V_280 ) ;
return 0 ;
}
static int F_178 ( struct V_173 * V_173 )
{
struct V_9 * V_10 = F_155 ( F_177 ( V_173 ) ) ;
int error ;
if ( V_10 -> V_170 ) {
error = F_122 ( V_10 ) ;
if ( error )
F_14 ( L_119 ) ;
}
return 0 ;
}
static int T_10 F_179 ( void )
{
int V_115 ;
if ( F_180 ( V_281 ) )
return - V_66 ;
V_164 = F_181 ( V_282 , V_283 ) ;
if ( ! V_164 ) {
F_13 ( L_120 V_282 L_121 ) ;
return - V_66 ;
}
V_115 = F_182 ( & V_284 ) ;
if ( V_115 ) {
F_13 ( L_122 , V_115 ) ;
F_92 ( V_282 , V_283 ) ;
}
return V_115 ;
}
static void T_11 F_183 ( void )
{
F_184 ( & V_284 ) ;
if ( V_164 )
F_92 ( V_282 , V_283 ) ;
}
