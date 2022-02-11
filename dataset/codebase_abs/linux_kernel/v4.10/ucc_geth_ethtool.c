static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return - V_9 ;
return F_3 ( V_8 , V_4 ) ;
}
static int
F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return - V_9 ;
return F_5 ( V_8 , V_4 ) ;
}
static void
F_6 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_11 -> V_12 = V_6 -> V_8 -> V_12 ;
if ( V_6 -> V_13 -> V_14 )
V_11 -> V_15 = 1 ;
if ( V_6 -> V_13 -> V_16 )
V_11 -> V_17 = 1 ;
}
static int
F_7 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_18 = 0 ;
V_6 -> V_13 -> V_14 = V_11 -> V_15 ;
V_6 -> V_13 -> V_16 = V_11 -> V_17 ;
if ( V_6 -> V_8 -> V_12 ) {
if ( F_8 ( V_2 ) ) {
F_9 ( V_2 , L_1 ) ;
}
} else {
struct V_19 * V_13 = V_6 -> V_13 ;
V_18 = F_10 ( V_13 -> V_20 ,
V_13 -> V_14 ,
V_13 -> V_16 ,
V_13 -> V_21 ,
V_13 -> V_22 ,
& V_6 -> V_23 -> V_24 -> V_25 ,
& V_6 -> V_26 -> V_27 ,
& V_6 -> V_26 -> V_28 ) ;
}
return V_18 ;
}
static T_1
F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_29 ;
}
static void
F_12 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_29 = V_30 ;
}
static int
F_13 ( struct V_1 * V_2 )
{
return sizeof( struct V_31 ) ;
}
static void
F_14 ( struct V_1 * V_2 ,
struct V_32 * V_33 , void * V_34 )
{
int V_35 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 T_3 * V_26 = ( T_2 T_3 * ) V_6 -> V_26 ;
T_2 * V_36 = V_34 ;
for ( V_35 = 0 ; V_35 < sizeof( struct V_31 ) / sizeof( T_2 ) ; V_35 ++ )
V_36 [ V_35 ] = F_15 ( & V_26 [ V_35 ] ) ;
}
static void
F_16 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_19 * V_13 = V_6 -> V_13 ;
int V_39 = 0 ;
V_38 -> V_40 = V_41 ;
V_38 -> V_42 = V_41 ;
V_38 -> V_43 = V_41 ;
V_38 -> V_44 = V_41 ;
V_38 -> V_45 = V_13 -> V_46 [ V_39 ] ;
V_38 -> V_47 = V_13 -> V_46 [ V_39 ] ;
V_38 -> V_48 = V_13 -> V_46 [ V_39 ] ;
V_38 -> V_49 = V_13 -> V_50 [ V_39 ] ;
}
static int
F_17 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_19 * V_13 = V_6 -> V_13 ;
int V_39 = 0 , V_18 = 0 ;
if ( V_38 -> V_45 < V_51 ) {
F_9 ( V_2 , L_2 ,
V_51 ) ;
return - V_52 ;
}
if ( V_38 -> V_45 % V_53 ) {
F_9 ( V_2 , L_3 ,
V_53 ) ;
return - V_52 ;
}
if ( V_38 -> V_49 < V_54 ) {
F_9 ( V_2 , L_4 ,
V_54 ) ;
return - V_52 ;
}
V_13 -> V_46 [ V_39 ] = V_38 -> V_45 ;
V_13 -> V_50 [ V_39 ] = V_38 -> V_49 ;
if ( F_8 ( V_2 ) ) {
F_9 ( V_2 , L_1 ) ;
}
return V_18 ;
}
static int F_18 ( struct V_1 * V_2 , int V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_56 = V_6 -> V_13 -> V_57 ;
int V_58 = 0 ;
switch ( V_55 ) {
case V_59 :
if ( V_56 & V_60 )
V_58 += V_61 ;
if ( V_56 & V_62 )
V_58 += V_63 ;
if ( V_56 & V_64 )
V_58 += V_65 ;
return V_58 ;
default:
return - V_66 ;
}
}
static void F_19 ( struct V_1 * V_2 , T_2 V_67 , T_4 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_56 = V_6 -> V_13 -> V_57 ;
if ( V_56 & V_60 ) {
memcpy ( V_68 , V_69 , V_61 *
V_70 ) ;
V_68 += V_61 * V_70 ;
}
if ( V_56 & V_62 ) {
memcpy ( V_68 , V_71 , V_63 *
V_70 ) ;
V_68 += V_63 * V_70 ;
}
if ( V_56 & V_64 )
memcpy ( V_68 , V_72 , V_65 *
V_70 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_73 * V_74 , T_5 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_56 = V_6 -> V_13 -> V_57 ;
T_2 T_3 * V_75 ;
int V_35 , V_76 = 0 ;
if ( V_56 & V_60 ) {
if ( V_6 -> V_26 )
V_75 = ( T_2 T_3 * ) & V_6 -> V_26 -> V_77 ;
else
V_75 = NULL ;
for ( V_35 = 0 ; V_35 < V_61 ; V_35 ++ )
V_30 [ V_76 ++ ] = V_75 ? F_15 ( & V_75 [ V_35 ] ) : 0 ;
}
if ( V_56 & V_62 ) {
V_75 = ( T_2 T_3 * ) V_6 -> V_78 ;
for ( V_35 = 0 ; V_35 < V_63 ; V_35 ++ )
V_30 [ V_76 ++ ] = V_75 ? F_15 ( & V_75 [ V_35 ] ) : 0 ;
}
if ( V_56 & V_64 ) {
V_75 = ( T_2 T_3 * ) V_6 -> V_79 ;
for ( V_35 = 0 ; V_35 < V_65 ; V_35 ++ )
V_30 [ V_76 ++ ] = V_75 ? F_15 ( & V_75 [ V_35 ] ) : 0 ;
}
}
static void
F_21 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
F_22 ( V_81 -> V_82 , V_83 , sizeof( V_81 -> V_82 ) ) ;
F_22 ( V_81 -> V_84 , V_85 , sizeof( V_81 -> V_84 ) ) ;
F_22 ( V_81 -> V_86 , L_5 , sizeof( V_81 -> V_86 ) ) ;
F_22 ( V_81 -> V_87 , L_6 , sizeof( V_81 -> V_87 ) ) ;
}
static void F_23 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 && V_8 -> V_90 )
V_89 -> V_91 |= V_92 ;
if ( F_24 () )
V_89 -> V_91 |= V_93 ;
V_89 -> V_94 = V_6 -> V_95 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_89 -> V_94 & ~ ( V_92 | V_93 ) )
return - V_52 ;
else if ( V_89 -> V_94 & V_92 && ( ! V_8 || ! V_8 -> V_90 ) )
return - V_52 ;
else if ( V_89 -> V_94 & V_93 && ! F_24 () )
return - V_52 ;
V_6 -> V_95 = V_89 -> V_94 ;
F_26 ( & V_2 -> V_96 , V_6 -> V_95 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_97 = & V_98 ;
}
