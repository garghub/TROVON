static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_6 -> V_10 ;
if ( ! V_8 )
return - V_11 ;
V_4 -> V_12 = 1 ;
V_4 -> V_13 = V_10 -> V_14 [ 0 ] ;
return F_3 ( V_8 , V_4 ) ;
}
static int
F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return - V_11 ;
return F_5 ( V_8 , V_4 ) ;
}
static void
F_6 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_16 -> V_17 = V_6 -> V_8 -> V_17 ;
if ( V_6 -> V_10 -> V_18 )
V_16 -> V_19 = 1 ;
if ( V_6 -> V_10 -> V_20 )
V_16 -> V_21 = 1 ;
}
static int
F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_22 = 0 ;
V_6 -> V_10 -> V_18 = V_16 -> V_19 ;
V_6 -> V_10 -> V_20 = V_16 -> V_21 ;
if ( V_6 -> V_8 -> V_17 ) {
if ( F_8 ( V_2 ) ) {
F_9 ( V_2 , L_1 ) ;
}
} else {
struct V_9 * V_10 = V_6 -> V_10 ;
V_22 = F_10 ( V_10 -> V_23 ,
V_10 -> V_18 ,
V_10 -> V_20 ,
V_10 -> V_24 ,
V_10 -> V_25 ,
& V_6 -> V_26 -> V_27 -> V_28 ,
& V_6 -> V_29 -> V_30 ,
& V_6 -> V_29 -> V_31 ) ;
}
return V_22 ;
}
static T_1
F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_32 ;
}
static void
F_12 ( struct V_1 * V_2 , T_1 V_33 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_32 = V_33 ;
}
static int
F_13 ( struct V_1 * V_2 )
{
return sizeof( struct V_34 ) ;
}
static void
F_14 ( struct V_1 * V_2 ,
struct V_35 * V_36 , void * V_37 )
{
int V_38 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 T_3 * V_29 = ( T_2 T_3 * ) V_6 -> V_29 ;
T_2 * V_39 = V_37 ;
for ( V_38 = 0 ; V_38 < sizeof( struct V_34 ) / sizeof( T_2 ) ; V_38 ++ )
V_39 [ V_38 ] = F_15 ( & V_29 [ V_38 ] ) ;
}
static void
F_16 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
int V_42 = 0 ;
V_41 -> V_43 = V_44 ;
V_41 -> V_45 = V_44 ;
V_41 -> V_46 = V_44 ;
V_41 -> V_47 = V_44 ;
V_41 -> V_48 = V_10 -> V_49 [ V_42 ] ;
V_41 -> V_50 = V_10 -> V_49 [ V_42 ] ;
V_41 -> V_51 = V_10 -> V_49 [ V_42 ] ;
V_41 -> V_52 = V_10 -> V_53 [ V_42 ] ;
}
static int
F_17 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
int V_42 = 0 , V_22 = 0 ;
if ( V_41 -> V_48 < V_54 ) {
F_9 ( V_2 , L_2 ,
V_54 ) ;
return - V_55 ;
}
if ( V_41 -> V_48 % V_56 ) {
F_9 ( V_2 , L_3 ,
V_56 ) ;
return - V_55 ;
}
if ( V_41 -> V_52 < V_57 ) {
F_9 ( V_2 , L_4 ,
V_57 ) ;
return - V_55 ;
}
V_10 -> V_49 [ V_42 ] = V_41 -> V_48 ;
V_10 -> V_53 [ V_42 ] = V_41 -> V_52 ;
if ( F_8 ( V_2 ) ) {
F_9 ( V_2 , L_1 ) ;
}
return V_22 ;
}
static int F_18 ( struct V_1 * V_2 , int V_58 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_59 = V_6 -> V_10 -> V_60 ;
int V_61 = 0 ;
switch ( V_58 ) {
case V_62 :
if ( V_59 & V_63 )
V_61 += V_64 ;
if ( V_59 & V_65 )
V_61 += V_66 ;
if ( V_59 & V_67 )
V_61 += V_68 ;
return V_61 ;
default:
return - V_69 ;
}
}
static void F_19 ( struct V_1 * V_2 , T_2 V_70 , T_4 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_59 = V_6 -> V_10 -> V_60 ;
if ( V_59 & V_63 ) {
memcpy ( V_71 , V_72 , V_64 *
V_73 ) ;
V_71 += V_64 * V_73 ;
}
if ( V_59 & V_65 ) {
memcpy ( V_71 , V_74 , V_66 *
V_73 ) ;
V_71 += V_66 * V_73 ;
}
if ( V_59 & V_67 )
memcpy ( V_71 , V_75 , V_68 *
V_73 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_76 * V_77 , T_5 * V_33 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_59 = V_6 -> V_10 -> V_60 ;
T_2 T_3 * V_78 ;
int V_38 , V_79 = 0 ;
if ( V_59 & V_63 ) {
if ( V_6 -> V_29 )
V_78 = ( T_2 T_3 * ) & V_6 -> V_29 -> V_80 ;
else
V_78 = NULL ;
for ( V_38 = 0 ; V_38 < V_64 ; V_38 ++ )
V_33 [ V_79 ++ ] = V_78 ? F_15 ( & V_78 [ V_38 ] ) : 0 ;
}
if ( V_59 & V_65 ) {
V_78 = ( T_2 T_3 * ) V_6 -> V_81 ;
for ( V_38 = 0 ; V_38 < V_66 ; V_38 ++ )
V_33 [ V_79 ++ ] = V_78 ? F_15 ( & V_78 [ V_38 ] ) : 0 ;
}
if ( V_59 & V_67 ) {
V_78 = ( T_2 T_3 * ) V_6 -> V_82 ;
for ( V_38 = 0 ; V_38 < V_68 ; V_38 ++ )
V_33 [ V_79 ++ ] = V_78 ? F_15 ( & V_78 [ V_38 ] ) : 0 ;
}
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_22 ( V_6 -> V_8 ) ;
}
static void
F_23 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
F_24 ( V_84 -> V_85 , V_86 , sizeof( V_84 -> V_85 ) ) ;
F_24 ( V_84 -> V_87 , V_88 , sizeof( V_84 -> V_87 ) ) ;
F_24 ( V_84 -> V_89 , L_5 , sizeof( V_84 -> V_89 ) ) ;
F_24 ( V_84 -> V_90 , L_6 , sizeof( V_84 -> V_90 ) ) ;
V_84 -> V_91 = 0 ;
V_84 -> V_92 = F_13 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 && V_8 -> V_95 )
V_94 -> V_96 |= V_97 ;
if ( F_26 () )
V_94 -> V_96 |= V_98 ;
V_94 -> V_99 = V_6 -> V_100 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_94 -> V_99 & ~ ( V_97 | V_98 ) )
return - V_55 ;
else if ( V_94 -> V_99 & V_97 && ( ! V_8 || ! V_8 -> V_95 ) )
return - V_55 ;
else if ( V_94 -> V_99 & V_98 && ! F_26 () )
return - V_55 ;
V_6 -> V_100 = V_94 -> V_99 ;
F_28 ( & V_2 -> V_101 , V_6 -> V_100 ) ;
return 0 ;
}
void F_29 ( struct V_1 * V_2 )
{
V_2 -> V_102 = & V_103 ;
}
