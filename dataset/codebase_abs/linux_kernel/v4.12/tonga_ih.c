static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_4 ) ;
V_3 = F_3 ( V_3 , V_5 , V_6 , 1 ) ;
V_3 = F_3 ( V_3 , V_5 , V_7 , 1 ) ;
F_4 ( V_4 , V_3 ) ;
V_2 -> V_8 . V_9 . V_10 = true ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_4 ) ;
V_3 = F_3 ( V_3 , V_5 , V_6 , 0 ) ;
V_3 = F_3 ( V_3 , V_5 , V_7 , 0 ) ;
F_4 ( V_4 , V_3 ) ;
F_4 ( V_11 , 0 ) ;
F_4 ( V_12 , 0 ) ;
V_2 -> V_8 . V_9 . V_10 = false ;
V_2 -> V_8 . V_9 . V_13 = 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_14 ;
T_1 V_15 , V_3 , V_16 ;
T_2 V_17 ;
F_5 ( V_2 ) ;
F_4 ( V_18 , V_2 -> V_19 . V_20 >> 8 ) ;
V_15 = F_2 ( V_21 ) ;
V_15 = F_3 ( V_15 , V_22 , V_23 , 0 ) ;
V_15 = F_3 ( V_15 , V_22 , V_24 , 0 ) ;
F_4 ( V_21 , V_15 ) ;
if ( V_2 -> V_8 . V_9 . V_25 )
F_4 ( V_26 , V_2 -> V_8 . V_9 . V_27 >> 8 ) ;
else
F_4 ( V_26 , V_2 -> V_8 . V_9 . V_28 >> 8 ) ;
V_14 = F_7 ( V_2 -> V_8 . V_9 . V_29 / 4 ) ;
V_3 = F_3 ( 0 , V_5 , V_30 , 1 ) ;
V_3 = F_3 ( V_3 , V_5 , V_31 , V_14 ) ;
V_3 = F_3 ( V_3 , V_5 , V_32 , 1 ) ;
V_3 = F_3 ( V_3 , V_5 , V_33 , 0 ) ;
if ( V_2 -> V_8 . V_34 )
V_3 = F_3 ( V_3 , V_5 , V_35 , 1 ) ;
F_4 ( V_4 , V_3 ) ;
if ( V_2 -> V_8 . V_9 . V_25 )
V_17 = V_2 -> V_8 . V_9 . V_27 + ( V_2 -> V_8 . V_9 . V_36 * 4 ) ;
else
V_17 = V_2 -> V_37 . V_28 + ( V_2 -> V_8 . V_9 . V_36 * 4 ) ;
F_4 ( V_38 , F_8 ( V_17 ) ) ;
F_4 ( V_39 , F_9 ( V_17 ) & 0xFF ) ;
F_4 ( V_11 , 0 ) ;
F_4 ( V_12 , 0 ) ;
V_16 = F_2 ( V_40 ) ;
if ( V_2 -> V_8 . V_9 . V_41 ) {
V_16 = F_3 ( V_16 , V_42 ,
V_43 , V_2 -> V_8 . V_9 . V_44 ) ;
V_16 = F_3 ( V_16 , V_42 ,
V_45 , 1 ) ;
} else {
V_16 = F_3 ( V_16 , V_42 ,
V_45 , 0 ) ;
}
F_4 ( V_40 , V_16 ) ;
F_10 ( V_2 -> V_46 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_12 ( 1 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
T_1 V_47 , V_48 ;
if ( V_2 -> V_8 . V_9 . V_25 )
V_47 = F_14 ( V_2 -> V_8 . V_9 . V_49 [ V_2 -> V_8 . V_9 . V_36 ] ) ;
else
V_47 = F_14 ( V_2 -> V_37 . V_37 [ V_2 -> V_8 . V_9 . V_36 ] ) ;
if ( F_15 ( V_47 , V_50 , V_51 ) ) {
V_47 = F_3 ( V_47 , V_50 , V_51 , 0 ) ;
F_16 ( V_2 -> V_52 , L_1 ,
V_47 , V_2 -> V_8 . V_9 . V_13 , ( V_47 + 16 ) & V_2 -> V_8 . V_9 . V_53 ) ;
V_2 -> V_8 . V_9 . V_13 = ( V_47 + 16 ) & V_2 -> V_8 . V_9 . V_53 ;
V_48 = F_2 ( V_4 ) ;
V_48 = F_3 ( V_48 , V_5 , V_30 , 1 ) ;
F_4 ( V_4 , V_48 ) ;
}
return ( V_47 & V_2 -> V_8 . V_9 . V_53 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
T_1 V_56 = V_2 -> V_8 . V_9 . V_13 >> 2 ;
T_3 V_57 [ 4 ] ;
V_57 [ 0 ] = F_14 ( V_2 -> V_8 . V_9 . V_49 [ V_56 + 0 ] ) ;
V_57 [ 1 ] = F_14 ( V_2 -> V_8 . V_9 . V_49 [ V_56 + 1 ] ) ;
V_57 [ 2 ] = F_14 ( V_2 -> V_8 . V_9 . V_49 [ V_56 + 2 ] ) ;
V_57 [ 3 ] = F_14 ( V_2 -> V_8 . V_9 . V_49 [ V_56 + 3 ] ) ;
V_55 -> V_58 = V_59 ;
V_55 -> V_60 = V_57 [ 0 ] & 0xff ;
V_55 -> V_61 [ 0 ] = V_57 [ 1 ] & 0xfffffff ;
V_55 -> V_62 = V_57 [ 2 ] & 0xff ;
V_55 -> V_63 = ( V_57 [ 2 ] >> 8 ) & 0xff ;
V_55 -> V_64 = ( V_57 [ 2 ] >> 16 ) & 0xffff ;
V_2 -> V_8 . V_9 . V_13 += 16 ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 . V_41 ) {
if ( V_2 -> V_8 . V_9 . V_25 )
V_2 -> V_8 . V_9 . V_49 [ V_2 -> V_8 . V_9 . V_65 ] = V_2 -> V_8 . V_9 . V_13 ;
else
V_2 -> V_37 . V_37 [ V_2 -> V_8 . V_9 . V_65 ] = V_2 -> V_8 . V_9 . V_13 ;
F_19 ( V_2 -> V_8 . V_9 . V_44 , V_2 -> V_8 . V_9 . V_13 ) ;
} else {
F_4 ( V_11 , V_2 -> V_8 . V_9 . V_13 ) ;
}
}
static int F_20 ( void * V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
int V_67 ;
V_67 = F_21 ( V_2 ) ;
if ( V_67 )
return V_67 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_23 ( void * V_66 )
{
int V_68 ;
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
V_68 = F_24 ( V_2 , 64 * 1024 , true ) ;
if ( V_68 )
return V_68 ;
V_2 -> V_8 . V_9 . V_41 = true ;
V_2 -> V_8 . V_9 . V_44 = V_69 ;
V_68 = F_25 ( V_2 ) ;
return V_68 ;
}
static int F_26 ( void * V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static int F_30 ( void * V_66 )
{
int V_68 ;
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
V_68 = F_6 ( V_2 ) ;
if ( V_68 )
return V_68 ;
return 0 ;
}
static int F_31 ( void * V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_32 ( void * V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
return F_31 ( V_2 ) ;
}
static int F_33 ( void * V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
return F_30 ( V_2 ) ;
}
static bool F_34 ( void * V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
T_1 V_48 = F_2 ( V_70 ) ;
if ( F_15 ( V_48 , V_71 , V_72 ) )
return false ;
return true ;
}
static int F_35 ( void * V_66 )
{
unsigned V_73 ;
T_1 V_48 ;
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_74 ; V_73 ++ ) {
V_48 = F_2 ( V_70 ) ;
if ( ! F_15 ( V_48 , V_71 , V_72 ) )
return 0 ;
F_36 ( 1 ) ;
}
return - V_75 ;
}
static bool F_37 ( void * V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
T_1 V_76 = 0 ;
T_1 V_48 = F_2 ( V_70 ) ;
if ( V_48 & V_77 )
V_76 = F_3 ( V_76 , V_78 ,
V_79 , 1 ) ;
if ( V_76 ) {
V_2 -> V_8 . V_76 = V_76 ;
return true ;
} else {
V_2 -> V_8 . V_76 = 0 ;
return false ;
}
}
static int F_38 ( void * V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
if ( ! V_2 -> V_8 . V_76 )
return 0 ;
return F_31 ( V_2 ) ;
}
static int F_39 ( void * V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
if ( ! V_2 -> V_8 . V_76 )
return 0 ;
return F_30 ( V_2 ) ;
}
static int F_40 ( void * V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
T_1 V_76 ;
if ( ! V_2 -> V_8 . V_76 )
return 0 ;
V_76 = V_2 -> V_8 . V_76 ;
if ( V_76 ) {
T_1 V_48 ;
V_48 = F_2 ( V_80 ) ;
V_48 |= V_76 ;
F_41 ( V_2 -> V_52 , L_2 , V_48 ) ;
F_4 ( V_80 , V_48 ) ;
V_48 = F_2 ( V_80 ) ;
F_36 ( 50 ) ;
V_48 &= ~ V_76 ;
F_4 ( V_80 , V_48 ) ;
V_48 = F_2 ( V_80 ) ;
F_36 ( 50 ) ;
}
return 0 ;
}
static int F_42 ( void * V_66 ,
enum V_81 V_82 )
{
return 0 ;
}
static int F_43 ( void * V_66 ,
enum V_83 V_82 )
{
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_84 == NULL )
V_2 -> V_8 . V_84 = & V_85 ;
}
