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
F_9 ( V_23
L_1 ) ;
}
} else {
struct V_9 * V_10 = V_6 -> V_10 ;
V_22 = F_10 ( V_10 -> V_24 ,
V_10 -> V_18 ,
V_10 -> V_20 ,
V_10 -> V_25 ,
V_10 -> V_26 ,
& V_6 -> V_27 -> V_28 -> V_29 ,
& V_6 -> V_30 -> V_31 ,
& V_6 -> V_30 -> V_32 ) ;
}
return V_22 ;
}
static T_1
F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_33 ;
}
static void
F_12 ( struct V_1 * V_2 , T_1 V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_33 = V_34 ;
}
static int
F_13 ( struct V_1 * V_2 )
{
return sizeof( struct V_35 ) ;
}
static void
F_14 ( struct V_1 * V_2 ,
struct V_36 * V_37 , void * V_38 )
{
int V_39 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 T_3 * V_30 = ( T_2 T_3 * ) V_6 -> V_30 ;
T_2 * V_40 = V_38 ;
for ( V_39 = 0 ; V_39 < sizeof( struct V_35 ) / sizeof( T_2 ) ; V_39 ++ )
V_40 [ V_39 ] = F_15 ( & V_30 [ V_39 ] ) ;
}
static void
F_16 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
int V_43 = 0 ;
V_42 -> V_44 = V_45 ;
V_42 -> V_46 = V_45 ;
V_42 -> V_47 = V_45 ;
V_42 -> V_48 = V_45 ;
V_42 -> V_49 = V_10 -> V_50 [ V_43 ] ;
V_42 -> V_51 = V_10 -> V_50 [ V_43 ] ;
V_42 -> V_52 = V_10 -> V_50 [ V_43 ] ;
V_42 -> V_53 = V_10 -> V_54 [ V_43 ] ;
}
static int
F_17 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
int V_43 = 0 , V_22 = 0 ;
if ( V_42 -> V_49 < V_55 ) {
F_9 ( L_2 ,
V_2 -> V_56 , V_55 ) ;
return - V_57 ;
}
if ( V_42 -> V_49 % V_58 ) {
F_9 ( L_3 ,
V_2 -> V_56 , V_58 ) ;
return - V_57 ;
}
if ( V_42 -> V_53 < V_59 ) {
F_9 ( L_4 ,
V_2 -> V_56 , V_59 ) ;
return - V_57 ;
}
V_10 -> V_50 [ V_43 ] = V_42 -> V_49 ;
V_10 -> V_54 [ V_43 ] = V_42 -> V_53 ;
if ( F_8 ( V_2 ) ) {
F_9 ( V_23
L_1 ) ;
}
return V_22 ;
}
static int F_18 ( struct V_1 * V_2 , int V_60 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_61 = V_6 -> V_10 -> V_62 ;
int V_63 = 0 ;
switch ( V_60 ) {
case V_64 :
if ( V_61 & V_65 )
V_63 += V_66 ;
if ( V_61 & V_67 )
V_63 += V_68 ;
if ( V_61 & V_69 )
V_63 += V_70 ;
return V_63 ;
default:
return - V_71 ;
}
}
static void F_19 ( struct V_1 * V_2 , T_2 V_72 , T_4 * V_73 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_61 = V_6 -> V_10 -> V_62 ;
if ( V_61 & V_65 ) {
memcpy ( V_73 , V_74 , V_66 *
V_75 ) ;
V_73 += V_66 * V_75 ;
}
if ( V_61 & V_67 ) {
memcpy ( V_73 , V_76 , V_68 *
V_75 ) ;
V_73 += V_68 * V_75 ;
}
if ( V_61 & V_69 )
memcpy ( V_73 , V_77 , V_70 *
V_75 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_78 * V_79 , T_5 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_61 = V_6 -> V_10 -> V_62 ;
T_2 T_3 * V_80 ;
int V_39 , V_81 = 0 ;
if ( V_61 & V_65 ) {
if ( V_6 -> V_30 )
V_80 = ( T_2 T_3 * ) & V_6 -> V_30 -> V_82 ;
else
V_80 = NULL ;
for ( V_39 = 0 ; V_39 < V_66 ; V_39 ++ )
V_34 [ V_81 ++ ] = V_80 ? F_15 ( & V_80 [ V_39 ] ) : 0 ;
}
if ( V_61 & V_67 ) {
V_80 = ( T_2 T_3 * ) V_6 -> V_83 ;
for ( V_39 = 0 ; V_39 < V_68 ; V_39 ++ )
V_34 [ V_81 ++ ] = V_80 ? F_15 ( & V_80 [ V_39 ] ) : 0 ;
}
if ( V_61 & V_69 ) {
V_80 = ( T_2 T_3 * ) V_6 -> V_84 ;
for ( V_39 = 0 ; V_39 < V_70 ; V_39 ++ )
V_34 [ V_81 ++ ] = V_80 ? F_15 ( & V_80 [ V_39 ] ) : 0 ;
}
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_22 ( V_6 -> V_8 ) ;
}
static void
F_23 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
F_24 ( V_86 -> V_87 , V_88 , sizeof( V_86 -> V_87 ) ) ;
F_24 ( V_86 -> V_89 , V_90 , sizeof( V_86 -> V_89 ) ) ;
F_24 ( V_86 -> V_91 , L_5 , sizeof( V_86 -> V_91 ) ) ;
F_24 ( V_86 -> V_92 , L_6 , sizeof( V_86 -> V_92 ) ) ;
V_86 -> V_93 = 0 ;
V_86 -> V_94 = F_13 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 && V_8 -> V_97 )
V_96 -> V_98 |= V_99 ;
if ( F_26 () )
V_96 -> V_98 |= V_100 ;
V_96 -> V_101 = V_6 -> V_102 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_96 -> V_101 & ~ ( V_99 | V_100 ) )
return - V_57 ;
else if ( V_96 -> V_101 & V_99 && ( ! V_8 || ! V_8 -> V_97 ) )
return - V_57 ;
else if ( V_96 -> V_101 & V_100 && ! F_26 () )
return - V_57 ;
V_6 -> V_102 = V_96 -> V_101 ;
F_28 ( & V_2 -> V_103 , V_6 -> V_102 ) ;
return 0 ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 , & V_104 ) ;
}
