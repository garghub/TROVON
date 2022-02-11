static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
T_2 V_5 [ V_4 ] ;
T_2 V_6 ;
T_1 V_7 = 0 ;
int V_8 ;
V_6 = ( V_3 & V_9 ) | V_10 ;
F_2 ( V_2 -> V_11 , V_6 , V_4 , V_5 ) ;
for ( V_8 = 0 ; V_8 < V_4 ; ++ V_8 )
V_7 |= ( V_5 [ V_8 ] << ( V_8 * V_12 ) ) ;
return V_7 ;
}
static void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 ,
T_1 V_13 )
{
T_2 V_5 [ V_4 ] ;
T_2 V_14 ;
int V_8 ;
V_14 = ( V_3 & V_9 ) | V_15 ;
for ( V_8 = 0 ; V_8 < V_4 ; ++ V_8 ) {
V_5 [ V_8 ] = ( V_13 >> ( V_8 * V_12 ) ) &
V_16 ;
}
F_4 ( V_2 -> V_11 , V_14 , V_4 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
T_1 V_7 = 0 ;
F_6 ( & V_2 -> V_17 ) ;
V_7 = F_1 ( V_2 , V_18 ,
V_19 ) ;
if ( V_7 > 0 )
F_3 ( V_2 , V_18 ,
V_19 , 0 ) ;
V_7 = 0 ;
while ( ( V_7 == 0 ) && ( V_8 ++ < V_20 ) ) {
F_7 ( V_21 ,
V_21 * 2 ) ;
V_7 = F_1 ( V_2 , V_18 ,
V_19 ) ;
}
if ( V_7 == 0 )
F_8 ( V_2 -> V_22 , L_1 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_17 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
T_1 V_13 ;
F_5 ( V_2 ) ;
V_13 = F_1 ( V_2 , V_3 , V_4 ) ;
F_9 ( V_2 ) ;
return V_13 ;
}
static void F_12 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 ,
T_1 V_13 )
{
int V_8 = 0 ;
T_1 V_7 = 0 , V_23 ;
F_6 ( & V_2 -> V_17 ) ;
V_7 = F_1 ( V_2 , V_18 ,
V_19 ) ;
while ( ( V_7 == 0 ) && ( V_8 ++ < V_20 ) ) {
F_7 ( V_21 ,
V_21 * 2 ) ;
V_7 = F_1 ( V_2 , V_18 ,
V_19 ) ;
}
if ( V_7 == 0 ) {
F_8 ( V_2 -> V_22 , L_2 ) ;
F_10 ( & V_2 -> V_17 ) ;
return;
}
F_3 ( V_2 , V_3 , V_4 , V_13 ) ;
V_8 = 0 ;
V_23 = V_7 ;
while ( ( V_7 == V_23 ) && ( V_8 ++ < V_20 ) ) {
F_7 ( V_21 ,
V_21 * 2 ) ;
V_7 = F_1 ( V_2 , V_18 ,
V_19 ) ;
}
F_10 ( & V_2 -> V_17 ) ;
if ( V_7 != ( V_23 + 1 ) )
F_8 ( V_2 -> V_22 , L_3 ,
V_3 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
union V_24 * V_13 )
{
V_13 -> V_25 = F_11 ( V_2 , V_26 ,
V_27 ) ;
if ( V_13 -> V_25 > 100 )
V_13 -> V_25 = 100 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
union V_24 * V_13 )
{
T_1 V_28 , V_29 , V_30 ;
T_3 div , V_7 ;
F_5 ( V_2 ) ;
V_28 = F_1 ( V_2 , V_31 ,
V_32 ) ;
V_30 = F_1 ( V_2 , V_33 ,
V_34 ) ;
V_29 = F_1 ( V_2 , V_35 ,
V_36 ) ;
F_9 ( V_2 ) ;
div = ( T_3 ) ( V_29 * V_30 * 65536ULL ) ;
F_15 ( div , 1000000 ) ;
V_7 = ( T_3 ) ( V_28 * 1000000ULL ) ;
F_15 ( V_7 , div ) ;
V_13 -> V_25 = ( int ) V_7 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
union V_24 * V_13 )
{
T_3 V_7 ;
V_13 -> V_25 = F_11 ( V_2 , V_37 ,
V_38 ) ;
V_7 = ( T_3 ) ( V_13 -> V_25 * 186ULL ) ;
F_15 ( V_7 , 10000 ) ;
V_13 -> V_25 = ( int ) V_7 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
union V_24 * V_13 )
{
V_13 -> V_25 = F_11 ( V_2 , V_39 ,
V_40 ) ;
V_13 -> V_25 = V_13 -> V_25 * 1000 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
union V_24 * V_13 )
{
V_13 -> V_25 = F_11 ( V_2 , V_41 ,
V_42 ) ;
V_13 -> V_25 = ( V_13 -> V_25 * 10 ) / 1048576 ;
return 0 ;
}
static int F_19 ( struct V_43 * V_44 ,
enum V_45 V_46 ,
union V_24 * V_13 )
{
struct V_1 * V_2 = F_20 ( V_44 -> V_22 . V_47 ) ;
int V_48 ;
switch ( V_46 ) {
case V_49 :
V_48 = F_13 ( V_2 , V_13 ) ;
break;
case V_50 :
V_48 = F_14 ( V_2 , V_13 ) ;
break;
case V_51 :
V_48 = F_16 ( V_2 , V_13 ) ;
break;
case V_52 :
V_48 = F_17 ( V_2 , V_13 ) ;
break;
case V_53 :
V_48 = F_18 ( V_2 , V_13 ) ;
break;
default:
V_48 = - V_54 ;
break;
}
return V_48 ;
}
static bool F_21 ( struct V_1 * V_2 )
{
union V_24 V_13 ;
F_13 ( V_2 , & V_13 ) ;
if ( V_13 . V_25 != V_2 -> V_55 ) {
V_2 -> V_55 = V_13 . V_25 ;
return true ;
}
return false ;
}
static void F_22 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_23 ( V_57 , struct V_1 , V_57 . V_57 ) ;
if ( F_21 ( V_2 ) )
F_24 ( V_2 -> V_58 ) ;
F_25 ( & V_2 -> V_57 , F_26 ( V_2 -> V_59 ) ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_11 ( V_2 , V_26 ,
V_27 ) ;
if ( V_55 > V_2 -> V_60 ) {
F_12 ( V_2 , V_61 ,
V_62 ,
V_2 -> V_60 + 1 ) ;
} else if ( ( V_55 <= V_2 -> V_60 ) && ( V_55 > V_2 -> V_63 ) ) {
F_12 ( V_2 , V_61 ,
V_62 ,
V_2 -> V_63 + 1 ) ;
F_12 ( V_2 , V_64 ,
V_65 ,
V_2 -> V_60 ) ;
} else if ( V_55 <= V_2 -> V_63 ) {
F_12 ( V_2 , V_64 ,
V_65 ,
V_2 -> V_63 ) ;
}
}
static T_4 F_28 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
T_1 V_68 ;
V_68 = F_1 ( V_2 , V_69 ,
V_70 ) ;
if ( V_68 & V_71 )
F_27 ( V_2 ) ;
F_3 ( V_2 , V_69 ,
V_70 , V_68 ) ;
return V_72 ;
}
static struct V_73 * F_29 ( struct V_74 * V_22 )
{
struct V_75 * V_76 = V_22 -> V_77 ;
struct V_73 * V_78 ;
V_78 = F_30 ( V_22 , sizeof( struct V_73 ) , V_79 ) ;
if ( ! V_78 )
return NULL ;
F_31 ( V_76 , L_4 ,
& V_78 -> V_80 ) ;
F_32 ( V_76 , L_5 ,
& V_78 -> V_81 ) ;
F_32 ( V_76 , L_6 ,
& V_78 -> V_82 ) ;
return V_78 ;
}
static int F_33 ( struct V_83 * V_84 )
{
struct V_74 * V_22 = & V_84 -> V_22 ;
struct V_11 * V_11 = F_20 ( V_22 -> V_47 ) ;
struct V_73 * V_85 = F_34 ( V_22 ) ;
struct V_1 * V_2 ;
int V_86 , V_66 , V_48 = 0 ;
V_2 = F_30 ( V_22 , sizeof( * V_2 ) , V_79 ) ;
if ( V_2 == NULL )
return - V_87 ;
F_35 ( V_84 , V_2 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_22 = V_22 ;
F_36 ( & V_2 -> V_17 ) ;
F_37 ( V_11 , V_88 , V_89 ,
V_89 ) ;
V_2 -> V_58 = F_38 ( V_22 , & V_90 , NULL ) ;
if ( F_39 ( V_2 -> V_58 ) ) {
V_48 = F_40 ( V_2 -> V_58 ) ;
return V_48 ;
}
V_86 = F_1 ( V_2 , V_91 ,
V_92 ) ;
F_41 ( V_22 , L_7 , V_86 ) ;
if ( V_22 -> V_77 ) {
V_85 = F_29 ( V_22 ) ;
V_22 -> V_93 = V_85 ;
}
if ( V_85 ) {
V_2 -> V_59 = V_85 -> V_80 ;
if ( V_85 -> V_81 > 100 )
F_42 ( V_22 , L_8 ) ;
else
V_2 -> V_60 = V_85 -> V_81 ;
if ( ( V_85 -> V_82 > 100 ) ||
( V_85 -> V_82 >= V_85 -> V_81 ) )
F_42 ( V_22 , L_9 ) ;
else
V_2 -> V_63 = V_85 -> V_82 ;
}
F_27 ( V_2 ) ;
if ( V_2 -> V_59 ) {
F_43 ( & V_2 -> V_57 , F_22 ) ;
F_25 ( & V_2 -> V_57 ,
F_26 ( V_2 -> V_59 ) ) ;
}
V_66 = F_44 ( V_84 , L_10 ) ;
if ( V_66 < 0 ) {
F_8 ( V_22 , L_11 , V_66 ) ;
V_48 = V_66 ;
goto V_94;
}
V_48 = F_45 ( V_22 , V_66 , NULL , F_28 ,
V_95 , L_10 , V_2 ) ;
if ( V_48 ) {
F_8 ( V_22 , L_12 , V_66 , V_48 ) ;
goto V_94;
}
return 0 ;
V_94:
if ( V_2 -> V_59 )
F_46 ( & V_2 -> V_57 ) ;
return V_48 ;
}
static int F_47 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_48 ( V_84 ) ;
if ( V_2 -> V_59 )
F_46 ( & V_2 -> V_57 ) ;
return 0 ;
}
static int F_49 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_48 ( V_84 ) ;
if ( V_2 -> V_59 )
F_50 ( & V_2 -> V_57 ) ;
return 0 ;
}
